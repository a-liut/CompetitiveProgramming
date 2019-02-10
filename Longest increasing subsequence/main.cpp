#include <iostream>
#include <vector>

using namespace std;

int64_t find_max(vector<int64_t> const &sequence, int64_t i, vector<int64_t> const &T)
{
	int64_t m = -1;
	for (int64_t j = 0; j < i; ++j)
	{
		if (sequence[j] < sequence[i] && (m == -1 || T[j] > T[m]))
		{
			m = j;
		}
	}
	return m;
}

int64_t lis(vector<int64_t> const &sequence)
{
	vector<int64_t> T(sequence.size(), 0);
	size_t max_idx = 0, best = 0;

	T[0] = 1;
	for (size_t i = 1; i < sequence.size(); ++i)
	{
		if (sequence[i] < sequence[max_idx])
		{
			// a new possible lis starts
			T[i] = 1;
			max_idx = i;
		}
		else
		{
			int64_t prefix_max = find_max(sequence, i, T);
			T[i] = 1 + (prefix_max != -1 ? T[prefix_max] : 0);

			if (T[i] > T[best])
				best = i;
		}
	}

	return T[best];
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

		cout << lis(sequence) << endl;
	}
}
