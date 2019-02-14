#include <iostream>
#include <string>
#include <vector>

using namespace std;

void compute_pi(string const &pattern, vector<int> &pi)
{
	int q = 0, k = -1;

	pi[0] = -1;
	for(q = 1; q < pattern.size(); ++q)
	{
		while (k >= 0 && pattern[q - 1] != pattern[k])
			k = pi[k];

		q++;
		k++;

		pi[q] = k;
	}
}

int kmp(string const &s, string const &pattern, vector<int> const pi)
{
	int q = 0, k = 0, max_prefix = -1, ans = -1;

	while (q < s.size())
	for(q = 1; q < s.size(); ++q)
	{
		while (k >= 0 && s[q - 1] != pattern[k])
			k = pi[k];

		k++;

		if (max_prefix < k)
		{
			cout << "q: " << q << ", k: " << k << endl;
			max_prefix = k;
			ans = q - k;
		}

		if (k == pattern.size())
			k = pi[k];
	}

	return ans;
}

int shifts(string const &a, string const &b)
{
	string s = b + b;
	vector<int> pi(b.size(), 0);

	compute_pi(a, pi);

	return kmp(s, a, pi);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	string a, p;

	cin >> x;

	cin >> a >> p;

	cout << shifts(a, p) << endl;
}
