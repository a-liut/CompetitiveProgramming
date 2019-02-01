#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100
#define MAX_M 100

using namespace std;

struct f_t {
	int32_t id, val;
};

class f_t_compare
{
  public:
    bool operator()(const f_t &lhs, const f_t &rhs) const
    {
        return lhs.val < rhs.val;
    }
};

typedef priority_queue<f_t, vector<f_t>, f_t_compare> f_priority_queue;

bool graph[MAX_N][MAX_N];

f_priority_queue max_f;
int8_t color[MAX_N];

void dfs_visit(int32_t pos, int32_t &time, int32_t nodes)
{
	time++;
	color[pos] = 1;

	for(int32_t i = 0; i < nodes; ++i)
	{
		if(graph[pos][i] && color[i] == 0) {
			dfs_visit(i, time, nodes);
		}
	}

	color[pos] = 2;
	time++;

	f_t el;
	el.id = pos;
	el.val = time;
	max_f.push(el);
}

int32_t connected_components(int32_t nodes)
{
	int32_t i, j, time = 0, ccs_no = 0;

	// init colors
	for(i = 0; i < nodes; ++i)
	{
		color[i] = 0;
	}

	// 1: DFS on G to fill f
	for(i = 0; i < nodes; ++i)
	{
		if(color[i] == 0)
		{
			dfs_visit(i, time, nodes);
		}
	}

	// 2: DFS on Gt using vertices ordered by decreasing f
	for(i = 0; i < nodes; ++i)
	{
		color[i] = 0;
	}
	time = 0;

	f_t current;
	while(!max_f.empty())
	{
		current = max_f.top();
		max_f.pop();

		if(color[current.id] == 0)
		{
			dfs_visit(current.id, time, nodes);
			ccs_no++;
		}
	}

	return ccs_no;
}

int32_t check_languages(int32_t employees)
{
	int32_t ccs = connected_components(employees);

	return ccs - 1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int32_t n, m, i, j, k, x;
	vector<vector<int32_t>> langs;
	bool skip = true;

	cin >> n >> m;

	langs.resize(m);

	for (i = 0; i < n; ++i)
	{
		cin >> k;

		if(k > 0) skip = false;

		for(j = 0; j < k; ++j)
		{
			cin >> x;

			// connect i with nodes that knows language x - 1
			for(auto l : langs[x - 1])
			{
				graph[l][i] = 1;
				graph[i][l] = 1;
			}

			langs[x - 1].push_back(i);
		}
	}

	if(skip) cout << n << endl;
	else cout << check_languages(n) << endl;
}