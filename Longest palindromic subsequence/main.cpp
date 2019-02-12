#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t palindromic(string &s)
{
	int64_t pal[s.length()][s.length()], i, j, k;

	for (i = 0; i < s.length(); ++i)
		for (j = 0; j < s.length(); ++j)
			pal[i][j] = 0;

	int64_t c = 0;
	for (j = 0; j < s.length(); ++j) 
		for (i = 0; i < s.length() - j; ++i)
			if (j == 0) pal[i][i + j] = 1;
			else if (s[i] == s[i + j]) pal[i][i + j] = 2 + pal[i + 1][i + j - 1];
			else pal[i][i + j] = max(pal[i + 1][i + j], pal[i][i + j - 1]);

	return pal[0][s.length() - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t n, i;
	string s;

	cin >> n;

	for (i = 0; i < n; ++i)
	{
		cin >> s;

		cout << palindromic(s) << endl;
	}
}
