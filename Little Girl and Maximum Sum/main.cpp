#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdint.h>

using namespace std;

class bit
{
  private:
	int64_t *elems;
	int64_t size;

  public:
	bit(int64_t size) : size(size)
	{
		elems = new int64_t[size + 1];
		for (int64_t i = 0; i <= size; i++)
			elems[i] = 0;
	}

	~bit()
	{
		delete elems;
	}

	void add(int64_t pos, int64_t v)
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

	int64_t sum(int64_t i)
	{
		int64_t s = elems[i];
		int64_t prev = i - (i & -i);
		while (prev > 0)
		{
			s += elems[prev];
			prev = prev - (prev & -prev);
		}

		return s;
	}

	int64_t rangeSum(int64_t a, int64_t b)
	{
		int64_t sa = sum(a - 1);
		int64_t sb = sum(b);

		return sb - sa;
	}
};

struct query_t
{
	int64_t l;
	int64_t r;
};

typedef pair<int64_t, int64_t> int64_t_pair;

int64_t maximum_sum_queries(vector<int64_t> &items, const vector<query_t> &queries) {
	int64_t i, n = items.size() + 1;
	priority_queue<int64_t_pair, vector<int64_t_pair>, less<int64_t_pair>> queue;

	// Prepare the frequency array: theta(n)
	int64_t F[n];
	for(i = 0; i < n; i++)
	{
		F[i] = 0;
	}

	// Compute the most hit locations by the queries: theta(q)
	for(auto query : queries) {
		F[query.l] += 1;
		if(query.r < items.size()) F[query.r + 1] -= 1;
	}

	// Put the elements into a priority queue: theta(n*log(n))
	int64_t sum = 0;
	for(i = 1; i < n; i++)
	{
		sum += F[i];
		int64_t_pair p;
		p.first = sum; // frequency
		p.second = i; // position

		queue.push(p);
	}

	// Sort values of items: O(n*log(n))
	std::sort(items.rbegin(), items.rend());

	// Extract elements from the queue and fill the array: theta(n*log(n))
	bit b(n);
	i = 0;
	while(!queue.empty()) {
		int64_t frequency = queue.top().first, position = queue.top().second;
        queue.pop();

		b.add(position, items[i]);
		i++;
    }

	// Compute the sums for the queries: O(q*log(n))
	int64_t result = 0;
	for(query_t query : queries)
	{
		result += b.rangeSum(query.l, query.r);
	}

	return result;
}

int main()
{
	int n, q, x, y, i;
	vector<int64_t> items;
	vector<query_t> queries;

	cin >> n;

	cin >> q;

	for (i = 0; i < n; i++)
	{
		cin >> x;

		items.push_back(x);
	}

	for (i = 0; i < q; i++)
	{
		cin >> x;
		cin >> y;

		query_t query;
		query.l = x;
		query.r = y;

		queries.push_back(query);
	}

	cout << maximum_sum_queries(items, queries) << endl;

	return 0;
}