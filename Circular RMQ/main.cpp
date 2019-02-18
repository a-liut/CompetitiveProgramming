#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <sstream>

#define PRINT_VEC(lab, v) cout << lab << "["; for(auto x : v) cout << x << " "; cout << "]" << endl;

#define LEFT(x) 2 * x + 1
#define RIGHT(x) 2 * x + 2

typedef int64_t int_type;
typedef int64_t intype;

using namespace std;

template <typename T>
class segment_tree
{
	private:
		vector<T> tree, lazy_tree;
		int n_leaves;

		void build(vector<T> const &leaves, int lo, int hi, int pos) {
            if (lo == hi) {
                tree[pos] = leaves[lo];
                return;
            }
            int mid = (lo + hi) / 2;
            build(leaves, lo, mid, LEFT(pos));
            build(leaves, mid + 1, hi, RIGHT(pos));
            tree[pos] = min(tree[LEFT(pos)], tree[RIGHT(pos)]);
        }

	public:
		segment_tree(int n)
		{
			n_leaves = n;
            int m = int(1) << static_cast<int>(ceil(log2(n)));
			int s = 2 * m - 1;
            tree.resize(s, T(0));
			lazy_tree.resize(s, T(0));
		}

		segment_tree(vector<T> &v) : segment_tree(v.size())
		{
			build(v, 0, v.size() - 1, 0);
		}

		int size() const {
			return n_leaves;
		}

		T _rmq(int r_lo, int r_hi, int s_lo, int s_hi, int pos)
		{
			if(lazy_tree[pos] != 0)
			{
				// cout << "rmq: applying lazy updates to " << pos << " (add " << lazy_tree[pos] << ")" << endl;
				tree[pos] += lazy_tree[pos];
				if(r_lo != r_hi)
				{
					lazy_tree[LEFT(pos)] += lazy_tree[pos];
					lazy_tree[RIGHT(pos)] += lazy_tree[pos];
				}

				lazy_tree[pos] = int_type(0);
			}

			// total overlap
			if (r_lo <= s_lo && r_hi >= s_hi)
				return tree[pos];
			
			// no overlap
			if (r_lo > s_hi ||  r_hi < s_lo)
				return int_type(INT64_MAX);

			// partial overlap
			int mid = (s_lo + s_hi) / 2;
			return min(
				_rmq(r_lo, r_hi, s_lo, mid, LEFT(pos)),
				_rmq(r_lo, r_hi, mid + 1, s_hi, RIGHT(pos))
			);
		}

		T rmq(int r_lo, int r_hi)
		{
			int c = size() - 1;
			if (r_lo <= r_hi)
				return _rmq(r_lo, r_hi, 0, c, 0);
			else
				return min(
					_rmq(0, r_hi, 0, c, 0),
					_rmq(r_lo, c, 0, c, 0)
				);
		}

		void _inc(int r_lo, int r_hi, int s_lo, int s_hi, int pos, T val)
		{
			// apply pending updates
			if(lazy_tree[pos] != 0)
			{
				// cout << "inc: applying lazy updates to " << pos << " : add " << lazy_tree[pos] << endl;
				tree[pos] += lazy_tree[pos];
				if(s_lo != s_hi)
				{
					// cout << "inc: updating also children: add " << lazy_tree[pos] << " to " << LEFT(pos) << ", " << RIGHT(pos) << endl;
					lazy_tree[LEFT(pos)] += lazy_tree[pos];
					lazy_tree[RIGHT(pos)] += lazy_tree[pos];
				}

				lazy_tree[pos] = int_type(0);
			}

			// no overlap
			if (r_lo > s_hi || r_hi < s_lo)
				return;

			// total overlap: postpone update
			if(r_lo <= s_lo && r_hi >= s_hi)
			{
				// cout << "inc: found total overlap. Adding " << val << " to tree["<< pos << "] = " << tree[pos] << endl;
				tree[pos] += val;
				if(s_lo != s_hi)
				{
					// cout << "inc: not a leaf, postponing the update" << endl;
					lazy_tree[LEFT(pos)] += val;
					lazy_tree[RIGHT(pos)] += val;
				}
				return;
			}

			// partial overlap
			int mid = (s_lo + s_hi) / 2;
			_inc(r_lo, r_hi, s_lo, mid, LEFT(pos), val);
			_inc(r_lo, r_hi, mid + 1, s_hi, RIGHT(pos), val);
			tree[pos] = min(tree[LEFT(pos)], tree[RIGHT(pos)]);
		}

		void inc(int r_lo, int r_hi, T val)
		{
			int c = size() - 1;
			if (r_lo <= r_hi)
			{
				// cout << "simple inc" << endl;
				_inc(r_lo, r_hi, 0, c, 0, val);
			}
			else
			{
				// cout << "circular inc (" << r_lo << ", " << r_hi << ")" << endl;
				// cout << "--- first inc 0-" << r_hi << endl;
				_inc(0, r_hi, 0, c, 0, val);
				// cout << "--- second inc "<< r_lo << "-" << c << endl;
				_inc(r_lo, c, 0, c, 0, val);
			}
		}

		void print()
		{
			PRINT_VEC("tree", tree);
			PRINT_VEC("lazy_tree", lazy_tree);
		}
};

int main()
{
	int_type n, m, x, i, com_idx;
	array<int_type, 3> com_args;
	vector<int_type> a;
	string temp;
	stringstream ss;

	cin >> n;
	a.resize(n);

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	segment_tree<int_type> st(a);

	cin >> m;

	getline(cin, temp);

	for (i = 0; i < m; i++)
	{
		getline(cin, temp);
		ss.clear();
		ss << temp;

		com_idx = 0;
		while (ss >> x)
		{
			com_args[com_idx] = x;
			com_idx++;
		}

		if (com_idx == 2)
		{
			// cout << "rmq: " << com_args[0] << ", " << com_args[1] << endl;
			cout << st.rmq(com_args[0], com_args[1]) << endl;
		}
		else
		{
			// cout << "inc: " << com_args[0] << ", " << com_args[1] << ", " << com_args[2] << endl;
			st.inc(com_args[0], com_args[1], com_args[2]);
		}
		
		// st.print();
	}
}
