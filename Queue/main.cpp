#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class fenwick
{
  private:
	vector<int64_t> elems;
	int64_t size;

  public:
	fenwick(int64_t size) : size(size)
	{
		elems.resize(size + 1);
		fill(elems.begin(), elems.end(), 0);
	}

	void add(int64_t pos, int64_t v)
	{
		elems[pos] += v;

		int64_t next = pos + (pos & -pos);
		while (next < size)
		{
			elems[next] += v;
			next = next + (next & -next);
		}
	}

	int64_t sum(int64_t i)
	{
		int64_t s = elems[i];
		int64_t prev = i - (i & -i);
		while (prev > 0)
		{
			s += elems[prev];
			prev = prev - (prev & -prev);
		}

		return s;
	}

	int64_t rangeSum(int64_t a, int64_t b)
	{
		int64_t sa = sum(a - 1);
		int64_t sb = sum(b - 1);

		return sb - sa;
	}
};

struct person_t
{
	string s;
	int64_t a, id, height;
};

void queue(vector<person_t> &people)
{
	int64_t i, k, count = 0, height;
	vector<person_t> ans(people.size());

	sort(people.begin(), people.end(), [](person_t &a, person_t &b) { return a.a < b.a; });

	for (i = 0; i < people.size(); ++i)
	{
		people[i].id = i;
		if (people[i].a > i)
		{
			cout << -1 << endl;
			return;
		}
	}

	fenwick bit(people.size());

	for (i = people.size() - 2; i >= 0; --i)
	{
		if (people[i].a == people[i + 1].a) count++;
		else count = 0;

		bit.add(i + 1, count);
	}

	for (i = people.size() - 1; i >= 0; --i)
	{
		k = bit.rangeSum(i + 1, people.size());
		ans[people[i].a + k] = people[i];
	}

	height = people.size();
	for (auto p : ans)
	{
		people[p.id].height = height;
		height--;
	}

	for(auto p : people)
	{
		cout << p.s << " " << p.height << endl;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t n, x, i;
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
