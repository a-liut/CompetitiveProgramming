#include <iostream>
#include <vector>

using namespace std;

int32_t longest_alternating_subsequence(vector<bool> &sequence)
{
	size_t count = 1, i, expected_pos = 0;

	for(i = 1; i < sequence.size(); ++i)
	{
		if(sequence[i] != sequence[expected_pos])
		{
			count++;
			expected_pos = i;
		}
	}

	return min(sequence.size(), count + 2);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	size_t n, i;
	char x;
	vector<bool> b;

	cin >> n;

	b.resize(n);

	cin.get(x);
	for (i = 0; i < n; ++i)
	{
		cin.get(x);
		b[i] = x == '1';
	}

	cout << longest_alternating_subsequence(b) << endl;
}
