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
	return val * (pow(occurrencies, 2));
}

void powerful_array(std::vector<int64_t> items, std::vector<query_t> queries)
{
	int64_t n = MAX_EL, s;
	int64_t current_l = 0, current_r = 0, answer = 0, block = (int64_t)sqrt(items.size());
	
	int64_t occurrencies[n], answers[queries.size()];

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
			s = power(items[current_l], occurrencies[items[current_l]]) - power(items[current_l], occurrencies[items[current_l]] - 1);
			occurrencies[items[current_l]]--;
			answer -= s;

			current_l++;
		}

		while (current_l > q.l)
		{
			current_l--;

			answer += power(items[current_l], occurrencies[items[current_l]] + 1) - power(items[current_l], occurrencies[items[current_l]]);
			occurrencies[items[current_l]]++;
		}

		while (current_r < q.r)
		{
			current_r++;

			answer += power(items[current_r], occurrencies[items[current_r]] + 1) - power(items[current_r], occurrencies[items[current_r]]);
			occurrencies[items[current_r]]++;
		}

		while (current_r > q.r)
		{
			s = power(items[current_r], occurrencies[items[current_r]]) - power(items[current_r], occurrencies[items[current_r]] - 1);
			occurrencies[items[current_r]]--;
			answer -= s;

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
	std::cin.tie(NULL);

	int64_t n, t, x, i;
	std::vector<int64_t> items;
	std::vector<query_t> queries;

	std::cin >> n >> t;

	items.resize(n + 1);
	items[0] = 0;
	for (i = 1; i <= n; i++)
	{
		std::cin >> x;

		items[i] = x;
	}

	queries.resize(t);
	for (i = 0; i < t; i++)
	{
		query_t q;

		std::cin >> x;
		q.l = x;

		std::cin >> x;
		q.r = x;

		q.idx = i;

		queries[i] = q;
	}

	powerful_array(items, queries);
}
