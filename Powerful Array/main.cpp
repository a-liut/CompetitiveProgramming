#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_EL 1000002 // 10^6

using namespace std;

struct query_t
{
	int64_t l, r, idx, answer;
};

void powerful_array(vector<int64_t> items, vector<query_t> queries)
{
	int64_t s;
	int64_t current_l = 0, current_r = 0, answer = 0, block = (int64_t)sqrt(items.size() - 1);
	
	vector<int64_t> occurrencies(MAX_EL, 0), answers(queries.size(), 0);

	auto cmp = [&](query_t const &q1, query_t const &q2) -> bool {
		int64_t first_bucket = q1.l / block;
		int64_t second_bucket = q2.l / block;

		if (first_bucket != second_bucket)
		{
			return first_bucket < second_bucket;
		}

		// Otherwise sort them by their right end
		return q1.r < q2.r;
	};

	// Sort queries by left end if they belongs to different blocks
	sort(queries.begin(), queries.end(), cmp);

	current_l = queries[0].l;
	current_r = current_l - 1;
	for (query_t &q : queries)
	{
		while (current_l < q.l)
		{
			occurrencies[items[current_l]]--;
			answer -= 2 * occurrencies[items[current_l]] * items[current_l] + items[current_l];

			current_l++;
		}

		while (current_l > q.l)
		{
			current_l--;

			answer += 2 * occurrencies[items[current_l]] * items[current_l] + items[current_l];
			occurrencies[items[current_l]]++;
		}

		while (current_r < q.r)
		{
			current_r++;

			answer += 2 * occurrencies[items[current_r]] * items[current_r] + items[current_r];
			occurrencies[items[current_r]]++;
		}

		while (current_r > q.r)
		{
			occurrencies[items[current_r]]--;
			answer -= 2 * occurrencies[items[current_r]] * items[current_r] + items[current_r];

			current_r--;
		}
		
		answers[q.idx] = answer;
	}

	for(int64_t i = 0; i < queries.size(); ++i)
	{
		cout << answers[i] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n, t, x, y, i;
	vector<int64_t> items;
	vector<query_t> queries;

	cin >> n >> t;

	items.resize(n + 1);
	items[0] = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> x;

		items[i] = x;
	}

	queries.resize(t);
	for (i = 0; i < t; i++)
	{
		cin >> x >> y;

		queries[i] = query_t {x, y, i};
	}

	powerful_array(items, queries);
}
