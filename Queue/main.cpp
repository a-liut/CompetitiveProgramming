#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person_t
{
	string s;
	int32_t a, id, height;
};

void queue(vector<person_t> &people)
{
	int32_t i, k, count = 0, height;
	vector<person_t> ans(people.size());
	vector<int64_t> height_arr;

	sort(people.begin(), people.end(), [](person_t &a, person_t &b) { return a.a < b.a; });

	for (i = 0; i < people.size(); ++i)
	{
		people[i].id = i;
		if (people[i].a > i)
		{
			cout << -1 << endl;
			return;
		}

		height_arr.insert(height_arr.begin() + i - people[i].a, i);
	}

	for (int i = 0; i < people.size(); i++)
	{
		people[height_arr[i]].height = i + 1;
	}

	for (auto p : people)
	{
		cout << p.s << " " << p.height << endl;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int32_t n, x, i;
	string s;
	vector<person_t> people;

	cin >> n;

	people.resize(n);

	for (i = 0; i < n; ++i)
	{
		cin >> s >> x;

		person_t p;
		p.s = s;
		p.a = x;

		people[i] = p;
	}

	queue(people);
}
