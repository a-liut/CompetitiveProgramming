#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

template <class T>
class bit
{
  private:
	std::vector<T> elems;

  public:
	typedef typename std::vector<T>::iterator iterator;

	bit(int64_t size)
	{
		elems.resize(size + 1);
	}

	void clear()
	{
		fill(elems.begin(), elems.end(), 0);
	}

	void add(int pos, T v)
	{
		// Update element at pos
		elems[pos] += v;

		// Update right sibilings and all right parents
		int next = pos + (pos & -pos);
		while (next < elems.size())
		{
			elems[next] += v;
			next = next + (next & -next);
		}
	}

	T sum(int i)
	{
		T s = elems[i];
		int prev = i - (i & -i);
		while (prev > 0)
		{
			s += elems[prev];
			prev = prev - (prev & -prev);
		}

		return s;
	}

	T rangeSum(int a, int b)
	{
		T sa = sum(a - 1);
		T sb = sum(b);

		return sb - sa;
	}

	inline iterator begin() noexcept { return elems.begin(); }
	inline iterator end() noexcept { return elems.end(); }
};


using namespace std;

struct range_t {
	int64_t id;
	int64_t l;
	int64_t r;
};

void nested_segments(vector<range_t> &ranges)
{
	bit<int64_t> tree(2 * ranges.size());
	vector<pair<int64_t, int64_t>> res;
	vector<int64_t> elems;

	for(auto r : ranges)
	{
		elems.push_back(r.l);
		elems.push_back(r.r);
	}

	// Map element into values in range [0, n - 1]
	sort(elems.begin(), elems.end());

	for(auto &r : ranges)
	{
		r.l = lower_bound(elems.begin(), elems.end(), r.l) - elems.begin();
		r.r = lower_bound(elems.begin(), elems.end(), r.r) - elems.begin();
	}

	// sort ranges by left index
	sort(ranges.begin(), ranges.end(), [](range_t r1, range_t r2) { return r1.l > r2.l; });

	for(auto r : ranges)
	{
		tree.add(r.r, 1);
		res.push_back(make_pair(r.id, tree.sum(r.r - 1)));
	}

	sort(res.begin(), res.end());

	for(auto p : res)
	{
		cout << p.second << endl;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t n, l, r;
	vector<range_t> ranges;

	cin >> n;

	for (int64_t i = 0; i < n; i++)
	{
		cin >> l >> r;

		range_t rng;
		rng.id = i;
		rng.l = l;
		rng.r = r;

		ranges.push_back(rng);
	}

	nested_segments(ranges);
}
