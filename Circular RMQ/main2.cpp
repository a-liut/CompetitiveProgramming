#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <sstream>

#define LEFT(x) (2 * x + 1)
#define RIGHT(x) (2 * x + 2)

using namespace std;

typedef int64_t int_type;

template <typename T>
struct segment_tree
{
  private:
    vector<T> tree;
    vector<T> lazy_tree;
    size_t n_leaves;

    void build(vector<T> const &leaves, size_t lo, size_t hi, size_t pos)
    {
        if (lo == hi)
        {
            tree[pos] = leaves[lo];
            return;
        }

        size_t mid = (lo + hi) / 2;
        build(leaves, lo, mid, LEFT(pos));
        build(leaves, mid + 1, hi, RIGHT(pos));
        tree[pos] = min(tree[LEFT(pos)], tree[RIGHT(pos)]);
    }

    void update_lazy_tree(size_t lo, size_t hi, size_t pos)
    {
        if (lazy_tree[pos] != 0)
        {
            tree[pos] += lazy_tree[pos];
            if (lo != hi)
            {
                lazy_tree[LEFT(pos)] += lazy_tree[pos];
                lazy_tree[RIGHT(pos)] += lazy_tree[pos];
            }
            lazy_tree[pos] = 0;
        }
    }

    int64_t _rmq(size_t r_lo, size_t r_hi, size_t s_lo, size_t s_hi, size_t pos)
    {
        update_lazy_tree(s_lo, s_hi, pos);

        // no overlap
        if (s_lo > r_hi || s_hi < r_lo || s_lo > s_hi)
            return int_type(INT64_MAX);

        // total overlap
        if (s_lo >= r_lo && s_hi <= r_hi)
            return tree[pos];

        // partial overlap
        size_t mid = (s_lo + s_hi) / 2;
        return min(
            _rmq(r_lo, r_hi, s_lo, mid, LEFT(pos)),
            _rmq(r_lo, r_hi, mid + 1, s_hi, RIGHT(pos)));
    }

    void _add(size_t r_lo, size_t r_hi, size_t s_lo, size_t s_hi, size_t pos, int64_t val)
    {
        update_lazy_tree(s_lo, s_hi, pos);

        // no overlap
        if (s_lo > r_hi || s_hi < r_lo)
            return;

        // total overlap
        if (s_lo >= r_lo && s_hi <= r_hi)
        {
            tree[pos] += val;
            if (s_lo != s_hi)
            {
                lazy_tree[LEFT(pos)] += val;
                lazy_tree[RIGHT(pos)] += val;
            }
            return;
        }

        // partial overlap
        size_t mid = (s_lo + s_hi) / 2;
        _add(r_lo, r_hi, s_lo, mid, LEFT(pos), val);
        _add(r_lo, r_hi, mid + 1, s_hi, RIGHT(pos), val);
        tree[pos] = min(tree[LEFT(pos)], tree[RIGHT(pos)]);
    }

  public:
    segment_tree(size_t n)
    {
        n_leaves = n;
        size_t m = size_t(1) << static_cast<size_t>(ceil(log2(n)));
        size_t s = 2 * m - 1;
        tree.resize(s, T(0));
        lazy_tree.resize(s, T(0));
    }

    segment_tree(vector<T> &v) : segment_tree(v.size())
    {
        build(v, 0, n_leaves - 1, 0);
    }

    int64_t rmq(size_t r_lo, size_t r_hi)
    {
        if (r_lo > r_hi)
            return min(
                _rmq(r_lo, n_leaves - 1, 0, n_leaves - 1, 0),
                _rmq(0, r_hi, 0, n_leaves - 1, 0));
        else
            return _rmq(r_lo, r_hi, 0, n_leaves - 1, 0);
    }

    void add(size_t r_lo, size_t r_hi, int64_t val)
    {
        if (r_lo > r_hi)
        {
            _add(r_lo, n_leaves - 1, 0, n_leaves - 1, 0, val);
            _add(0, r_hi, 0, n_leaves - 1, 0, val);
        }
        else
            _add(r_lo, r_hi, 0, n_leaves - 1, 0, val);
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
        cin >> a[i];

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
            cout << st.rmq(com_args[0], com_args[1]) << endl;
        else
            st.add(com_args[0], com_args[1], com_args[2]);
    }
}
