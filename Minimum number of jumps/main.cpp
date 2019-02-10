#include <iostream>
#include <vector>

using namespace std;

int64_t find_min(vector<int64_t> const &sequence, vector<int64_t> const &jumps, size_t i)
{
	int64_t m = -1;
	for(size_t j = 0; j < i; ++j)
	{
		if(jumps[j] > -1 && (j + sequence[j] >= i) && (m == -1 || (1 + jumps[j]) < jumps[m])) m = j;
	}

	return m;
}

int64_t jumps(vector<int64_t> const &sequence)
{
	vector<int64_t> jumps(sequence.size(), 0);
	int64_t min_idx = 0;

	for(size_t i = 1; i < sequence.size(); ++i)
	{
		min_idx = find_min(sequence, jumps, i);
		jumps[i] = min_idx == -1 ? -1 : (1 + jumps[min_idx]);
	}

	return jumps[sequence.size() - 1];
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

		cout << jumps(sequence) << endl;
	}
}
