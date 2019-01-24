#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_EL 1000002 // 10^6

struct query_t
{
	int64_t l, r, idx, answer;
};

int64_t power(int64_t val, int64_t occurrencies)
{
	return val * (occurrencies * occurrencies);
}

void add(std::vector<int64_t> &items, int64_t *occurrencies, int64_t pos, int64_t &answer)
{
	int64_t s = power(items[pos], occurrencies[items[pos]] + 1) - power(items[pos], occurrencies[items[pos]]);
	answer += s;
	occurrencies[items[pos]]++;
}

void remove(std::vector<int64_t> &items, int64_t *occurrencies, int64_t pos, int64_t &answer)
{
	int64_t s = power(items[pos], occurrencies[items[pos]]) - power(items[pos], occurrencies[items[pos]] - 1);
	occurrencies[items[pos]]--;
	answer -= s;
}

void powerful_array(std::vector<int64_t> items, std::vector<query_t> queries)
{
	int64_t n = MAX_EL;
	int64_t current_l = 0, current_r = 0, answer = 0, block = (int64_t)sqrt(items.size());
	int64_t occurrencies[n];
	int64_t answers[queries.size()];

	for (int64_t i = 0; i < n; ++i)
	{
		occurrencies[i] = 0;
	}

	// Sort queries by left end if they belongs to different blocks
	std::sort(queries.begin(), queries.end(), [&](query_t q1, query_t q2) {
		int64_t first_bucket = (int64_t)floor(q1.l / block);
		int64_t second_bucket = (int64_t)floor(q2.l / block);

		if (first_bucket != second_bucket)
		{
			return first_bucket < second_bucket;
		}

		// Otherwise sort them by their right end
		return q1.r < q2.r;
	});

	for (query_t &q : queries)
	{
		while (current_l < q.l)
		{
			remove(items, occurrencies, current_l, answer);
			current_l++;
		}

		while (current_l > q.l)
		{
			current_l--;
			add(items, occurrencies, current_l, answer);
		}

		while (current_r < q.r)
		{
			current_r++;
			add(items, occurrencies, current_r, answer);
		}

		while (current_r > q.r)
		{
			remove(items, occurrencies, current_r, answer);
			current_r--;
		}
		
		answers[q.idx] = answer;
	}

	for(int64_t i = 0; i < queries.size(); ++i)
	{
		std::cout << answers[i] << std::endl;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int64_t n, t, x, i;
	std::vector<int64_t> items;
	std::vector<query_t> queries;

	std::cin >> n >> t;

	items.reserve(n);
	items.push_back(0);
	for (i = 0; i < n; i++)
	{
		std::cin >> x;

		items.push_back(x);
	}

	queries.reserve(t);
	for (i = 0; i < t; i++)
	{
		query_t q;

		std::cin >> x;
		q.l = x;

		std::cin >> x;
		q.r = x;

		q.idx = i;

		queries.push_back(q);
	}

	powerful_array(items, queries);
}
