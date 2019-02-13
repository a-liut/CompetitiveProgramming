#include <iostream>

#define MAX_LENGTH 100000

using namespace std;

size_t pi[MAX_LENGTH], k, q;

size_t lps(string &s)
{
	pi[0] = 0;
	k = 0;
	for (q = 1; q < s.length(); ++q)
	{
		while (k > 0 && s[k] != s[q])
			k = pi[k];

		if (s[k] == s[q])
			k++;

		pi[q] = k;
	}

	return pi[s.length() - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	size_t t, i;
	string s;

	cin >> t;

	for (i = 0; i < t; ++i)
	{
		cin >> s;

		cout << lps(s) << endl;
	}
}
