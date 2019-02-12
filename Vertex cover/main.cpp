#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

void _vc(int64_t pos, int64_t parent, vector<vector<int64_t>> const &edges, int64_t T[MAX_N][2])
{
	T[pos][1] = 1;
	T[pos][0] = 0;
	
	for(auto e : edges[pos])
	{
		if(e != parent)
		{
			_vc(e, pos, edges, T);
			T[pos][1] += min(T[e][0], T[e][1]);
			T[pos][0] += T[e][1];
		}
	}
}

int64_t vertex_cover(int64_t n, vector<vector<int64_t>> const &edges)
{
	int64_t T[MAX_N + 1][2];

	for(int i = 0; i < MAX_N + 1; ++i)
	{
		T[i][0] = 0;
		T[i][1] = 0;
	}

	_vc(1, 0, edges, T);

	return max(min(T[1][0], T[1][1]), (int64_t) 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t i, n, x, y;
	vector<vector<int64_t>> edges;

	cin >> n;

	edges.resize(n + 1);

	for (i = 0; i < n - 1; ++i)
	{
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	cout << vertex_cover(n, edges) << endl;
}
