#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

template <typename T>
pair<T, T> find_pair(vector<T> &a, int64_t k)
{
	int64_t i = 0, x, y, n = a.size(), l = 0, r = 0; // l: number of keys smaller that x, r: keys equals to x
	sort(a.begin(), a.end());

	x = (k - 1) / n;

	while (i < n && a[i] < a[x])
	{
		l++;
		i++;
	}

	while (i < n && a[i] == a[x])
	{
		r++;
		i++;
	}

	y = ((k - 1) - l * n) / r;

	return make_pair(a[x], a[y]);
}

int main()
{
	int64_t n, k;
	int64_t x;
	vector<int64_t> a;

	cin >> n;
	cin >> k;

	for (int64_t i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}

	pair<int64_t, int64_t> res = find_pair(a, k);

	cout << res.first << " " << res.second << endl;
}
