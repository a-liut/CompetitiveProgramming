#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge_t
{
	int64_t left, right, weight;
};

int64_t find_set(vector<int64_t> &nodes, int64_t pos)
{
	if(nodes[pos] == -1) return pos;
	return nodes[pos] = find_set(nodes, nodes[pos]); // path compression
}

void link(vector<int64_t> &nodes, int64_t u, int64_t v)
{
	if(nodes[u] < nodes[v])
	{
		nodes[v] = u;
	} else
	{
		nodes[u] = v;
		if(nodes[u] == nodes[v])
		{
			nodes[v]++;
		}
	}	
}

void set_union(vector<int64_t> &nodes, int64_t u, int64_t v)
{
	link(nodes, find_set(nodes, u), find_set(nodes, v));
}

int64_t mst(int64_t n, vector<edge_t> &edges)
{
	// Apply kruskal algorithm
	int64_t min_weight = 0;
	vector<int64_t> nodes;
	nodes.assign(n, -1);

	sort(edges.begin(), edges.end(), [](edge_t &a, edge_t &b){
		return a.weight < b.weight;
	});

	for(edge_t e : edges)
	{
		if(find_set(nodes, e.left) != find_set(nodes, e.right))
		{
			set_union(nodes, e.left, e.right);
			min_weight += e.weight;
		}
	}

	return min_weight;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int32_t n, m, i, a, b, w;
	vector<edge_t> edges;

	cin >> n >> m;

	edges.resize(n);

	for (i = 0; i < m; ++i)
	{
		cin >> a >> b >> w;

		edge_t e;
		e.left = a - 1;
		e.right = b - 1;
		e.weight = w;

		edges.push_back(e);
	}

	cout << mst(n, edges) << endl;
}
