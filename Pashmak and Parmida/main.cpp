#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

template <class T>
class bit
{
  private:
	std::vector<T> elems;
	int64_t size;

  public:
	typedef typename std::vector<T>::iterator iterator;

	bit(int64_t size): size(size)
	{
		elems.resize(size + 1, 0);
	}

	void clear()
	{
		fill(elems.begin(), elems.end(), 0);
	}

	void add(int64_t pos, T v)
	{
		// Update element at pos
		elems[pos] += v;

		// Update right sibilings and all right parents
		int64_t next = pos + (pos & -pos);
		while (next < size)
		{
			elems[next] += v;
			next = next + (next & -next);
		}
	}

	T sum(int64_t i)
	{
		T s = elems[i];
		int64_t prev = i - (i & -i);
		while (prev > 0)
		{
			s += elems[prev];
			prev = prev - (prev & -prev);
		}

		return s;
	}

	T rangeSum(int64_t a, int64_t b)
	{
		T sa = sum(a - 1);
		T sb = sum(b);

		return sb - sa;
	}

	inline iterator begin() noexcept { return elems.begin(); }
	inline iterator end() noexcept { return elems.end(); }
};

int64_t pashmak(std::vector<int64_t> &elems)
{
	int64_t i;

	// Map values into range [0-1]
	std::vector<int64_t> allElems(elems);

	std::sort(allElems.begin(), allElems.end());

	for(int64_t &el : elems)
	{
		el = std::lower_bound(allElems.begin(), allElems.end(), el) - allElems.begin();
	}

	// Compute the SuffixCounter array: SC[i] = f(j, n, elems[j])
	std::vector<int64_t> suffixCounter(elems.size(), 0), counter(elems.size(), 0);
	bit<int64_t> tree(suffixCounter.size());
	i = elems.size() - 1;
	for(i = elems.size() - 1; i >= 0; --i)
	{
		counter[elems[i]]++;
		suffixCounter[i] = counter[elems[i]];
		tree.add(suffixCounter[i], 1);
	}

	// Reuse the same counter vector object
	std::fill(counter.begin(), counter.end(), 0);
	int64_t res = 0;

	// Compute f(1, i, A[i])
	for(i = 0; i < elems.size(); ++i)
	{
		counter[elems[i]]++; //f(1, i, A[i])
		tree.add(suffixCounter[i], -1);
		res += tree.sum(counter[elems[i]] - 1);
	}
	
	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int64_t n, x;
	std::vector<int64_t> elems;

	std::cin >> n;
	elems.resize(n, 0);

	for (int64_t i = 0; i < n; i++)
	{
		std::cin >> x;
		elems[i] = x;
	}

	std::cout << pashmak(elems) << std::endl;
}
