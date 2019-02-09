#include <iostream>
#include <vector>

using namespace std;

int64_t knapsack(vector<int64_t> &val, vector<int64_t> &wt, int64_t W)
{
	int64_t table[val.size() + 1][W + 1], temp;

	for (int64_t i = 0; i <= val.size(); ++i)
		for (int64_t j = 0; j <= W; ++j)
		{
			if (i == 0 || j == 0)
				table[i][j] = 0;
			else
			{
				temp = ((j - wt[i - 1]) >= 0) ? (table[i - 1][j - wt[i - 1]] + val[i - 1]) : 0;
				table[i][j] = max(table[i - 1][j], temp);
			}
		}

	return table[val.size()][W];
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t t, i, j, N, W, x;
	vector<int64_t> val, wt;

	cin >> t;

	for (i = 0; i < t; ++i)
	{
		cin >> N >> W;

		val.clear();
		val.resize(N);

		wt.clear();
		wt.resize(N);

		for (j = 0; j < N; ++j)
		{
			cin >> x;
			val[j] = x;
		}

		for (j = 0; j < N; ++j)
		{
			cin >> x;
			wt[j] = x;
		}

		cout << knapsack(val, wt, W) << endl;
	}
}
