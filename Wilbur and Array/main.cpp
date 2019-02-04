#include <iostream>
#include <vector>

using namespace std;

int64_t updates(vector<int64_t> &b)
{
	int64_t count = abs(b[0]);

	for (size_t i = 1; i < b.size(); ++i) count += abs(b[i - 1] - b[i]);

	return count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	size_t n, i;
	int64_t x;
	vector<int64_t> b;

	cin >> n;

	b.resize(n);

	for (i = 0; i < n; ++i)
	{
		cin >> x;
		b[i] = x;
	}

	cout << updates(b) << endl;
}
