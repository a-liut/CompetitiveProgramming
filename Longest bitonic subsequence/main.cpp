#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
int64_t binary_search(vector<T> const &v, size_t begin, size_t end, T x)
{
	while (end - begin > 1)
	{
		int64_t mid = (begin + end) / 2;
		if (x == v[mid])
			return mid;
		else if (x <= v[mid])
			end = mid;
		else
			begin = mid;
	}

	return end;
}

vector<int64_t> lis(std::vector<int64_t> &v)
{
	vector<int64_t> ans;

	if (v.size() == 0)
		return ans;

	std::vector<int64_t> tail(v.size(), 0);
	int64_t length = 1;

	ans.reserve(v.size());

	tail[0] = v[0];
	ans.push_back(1);
	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] < tail[0])
		{
			tail[0] = v[i];
			ans.push_back(1);
		}
		else if (v[i] > tail[length - 1])
		{
			tail[length++] = v[i];
			ans.push_back(length);
		}
		else
		{
			int64_t idx = binary_search(tail, -1, length - 1, v[i]);
			tail[idx] = v[i];
			ans.push_back(++idx);
		}
	}

	return ans;
}

int64_t bitonic(vector<int64_t> &sequence)
{
	vector<int64_t> ltr = lis(sequence);

	reverse(sequence.begin(), sequence.end());

	vector<int64_t> rtl = lis(sequence);

	int64_t max = ltr.front() + rtl.back();
	int64_t temp = max;
	for (size_t i = 1; i < ltr.size(); ++i)
	{
		temp = ltr[i] + rtl[rtl.size() - 1 - i];
		if (temp > max)
		{
			max = temp;
		}
	}

	return --max;
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

		cout << bitonic(sequence) << endl;
	}
}
