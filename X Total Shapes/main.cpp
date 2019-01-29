#include <iostream>

#define MAX_N 50 * 50

typedef int64_t intType;

using namespace std;

intType ox[MAX_N][MAX_N];
bool graph[MAX_N][MAX_N];
bool visit[MAX_N];

void clean()
{
		// clean tables
		for(size_t j = 0; j < MAX_N; ++j)
		{
			for(size_t y = 0; y < MAX_N; ++y) {
				graph[j][y] = false;
				ox[j][y] = -1;
			}
			visit[j] = false;
		}
}

void dfs_visit(size_t node, size_t nodes_no)
{
	visit[node] = true;

	for(size_t i = 0; i < nodes_no; ++i)
	{
		if(graph[node][i] && !visit[i]) {
			dfs_visit(i, nodes_no);
		}
	}
}

intType x_shapes(size_t nodes_no)
{
	intType count = 0;

	for(size_t i = 0; i < nodes_no; ++i)
	{
		if(!visit[i])
		{
			dfs_visit(i, nodes_no);
			count++;
		}
	}

	return count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	intType t, m, i, j;
	size_t n, y;
	string buf;

	cin >> t;

	for(i = 0; i < t; ++i)
	{
		intType idx = 0;
		cin >> n >> m;

		for(j = 0; j < n; ++j)
		{
			cin >> buf;

			for(y = 0; y < buf.size(); ++y)
			{
				char c = buf[y];
				if(c == 'X') // Node
				{
					ox[j][y] = idx;

					if(j > 0 && ox[j - 1][y] != -1)
					{
						// Make the edge
						graph[idx][ox[j - 1][y]] = true;
						graph[ox[j - 1][y]][idx] = true;
					}

					if(y > 0 && ox[j][y - 1] != -1)
					{ 
						graph[idx][ox[j][y - 1]] = true;
						graph[ox[j][y - 1]][idx] = true;
					}

					idx++;
				} else {
					ox[j][y] = -1;
				}
			}
		}

		cout << x_shapes(idx) << endl;

		clean();
	}
}
