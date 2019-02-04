#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct job_t
{
	size_t id;
	int64_t start, finish;
};

void select_jobs(vector<job_t> &jobs)
{
	size_t last_selected = -1;

	sort(jobs.begin(), jobs.end(), [](job_t &a, job_t &b) { return a.finish < b.finish; });

	for(size_t i = 0; i < jobs.size(); ++i)
	{
		if(last_selected == -1 || jobs[last_selected].finish < jobs[i].start)
		{
			last_selected = i;

			cout << jobs[i].id << " ";
		}
	}

	cout << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	size_t t, n, i, j;
	int64_t x;
	vector<job_t> jobs;

	cin >> t;

	for (i = 0; i < t; ++i)
	{
		cin >> n;

		jobs.clear();
		jobs.resize(n);

		for (j = 0; j < n; ++j)
		{
			cin >> x;

			jobs[j].id = j + 1;
			jobs[j].start = x;
		}

		for (j = 0; j < n; ++j)
		{
			cin >> x;

			jobs[j].finish = x;
		}

		select_jobs(jobs);
	}
}
