#include <iostream>
#include <vector>

using namespace std;

bool subset_sum(vector<int64_t> sequence)
{
	int64_t size = 0;
	for(int64_t x : sequence) size += x;

	if(size % 2 != 0) return false;

	size = size / 2;

	bool T[sequence.size() + 1][size + 1];

	for(int64_t i = 0; i <= sequence.size(); ++i)
	{
		for(int64_t j = 0; j <= size; ++j)
		{
			if(i == 0 && j != 0) T[i][j] = false;
			else if (j == 0) T[i][j] = true;
			else 
			{
				int64_t idx = j - sequence[i - 1];
				T[i][j] = (idx >= 0 ? T[i - 1][idx] : false) || T[i - 1][j];
			}
		}
	}

	return T[sequence.size()][size];
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t t, i, j, n, x;
	vector<int64_t> sequence;

	cin >> t;

	for (i = 0; i < t; ++i)
	{
		cin >> n;

		sequence.clear();
		sequence.resize(n);

		for (j = 0; j < n; ++j)
		{
			cin >> x;
			sequence[j] = x;
		}

		cout << (subset_sum(sequence) ? "YES" : "NO") << endl;
	}
}
