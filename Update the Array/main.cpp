#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

using namespace std;

template <class T>
class bit
{
  private:
	vector<T> elems;

  public:
	typedef typename vector<T>::iterator iterator;

	void init(int size)
	{
		elems.resize(size + 1);
		clear();
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

int main()
{
	int testno, n, u, l, r, val, i, j;
	bit<int> BIT;

	cin >> testno;

	for (i = 0; i < testno; i++)
	{
		cin >> n;
		cin >> u;

		BIT.init(n);

		for (j = 0; j < u; j++)
		{
			cin >> l;
			cin >> r;
			cin >> val;

			BIT.add(l + 1, val);
			if (r < n - 1)
			{
				BIT.add(r + 2, -val);
			}
		}

		cin >> n;
		// Queries
		for(j = 0; j < n; j++)
		{
			cin >> val;

			cout << BIT.sum(val + 1) << endl;
		}
	}

	return 0;
}
