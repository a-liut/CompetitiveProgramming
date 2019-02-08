#include <iostream>
#include <vector>

#define MAX_LENGTH 100

using namespace std;

int64_t lcs(string &a, string &b)
{
	int64_t i, j;
	int64_t table[MAX_LENGTH + 1][MAX_LENGTH + 1];

	for (i = 0; i <= a.length(); ++i)
	{
		for (j = 0; j <= b.length(); ++j)
		{
			if(i == 0 || j == 0) {
				table[i][j] = 0;
			} else if(a[i - 1] == b[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			} else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}

	return table[a.length()][b.length()];
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t t, n1, n2, i;
	string s1, s2;

	cin >> t;

	for (i = 0; i < t; ++i)
	{
		cin >> n1 >> n2;

		cin >> s1 >> s2;

		cout << lcs(s1, s2) << endl;
	}
}
