#include <iostream>
#include <vector>

using namespace std;

int64_t edit_distance(string const &a, string const &b)
{
	int64_t T[a.size() + 1][b.size() + 1];

	for (size_t i = 0; i <= a.size(); ++i)
		for (size_t j = 0; j <= b.size(); ++j)
			if (i == 0)
				T[i][j] = j;
			else if (j == 0)
				T[i][j] = i;
			else if (a[i - 1] == b[j - 1])
				T[i][j] = T[i - 1][j - 1];
			else
				T[i][j] = 1 + min(T[i - 1][j], min(T[i][j - 1], T[i - 1][j - 1]));

	return T[a.size()][b.size()];
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t t, i, n;
	string a, b;

	cin >> t;

	for (i = 0; i < t; ++i)
	{
		cin >> n >> n;

		cin >> a >> b;

		cout << edit_distance(a, b) << endl;
	}
}
