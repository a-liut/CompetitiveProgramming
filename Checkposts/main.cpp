#include <iostream>
#include <vector>
#include <queue>

#define MAX_WAYS 1000000007

using namespace std;

struct node_t
{
	int64_t cost, f, color, id;
	vector<int64_t> neighbors;
};

struct f_t
{
	int64_t id, val;
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

void dfs_visit(vector<node_t> &nodes, int64_t pos, int64_t &time, int64_t &min, int64_t &mult)
{
	time++;
	nodes[pos].color = 1;

	if(nodes[pos].cost < min) {
		min = nodes[pos].cost;
		mult = 1;
	} else if(nodes[pos].cost == min) {
		mult++;
	}

	for(int64_t neigh_idx : nodes[pos].neighbors)
	{
		node_t neigh = nodes[neigh_idx];
		if(neigh.color == 0) {
			dfs_visit(nodes, neigh_idx, time, min, mult);
		}
	}

	time++;
	nodes[pos].color = 2;
	nodes[pos].f = time;
}

void checkposts(vector<node_t> &nodes)
{
	int64_t time = 0, cc_min = INT_MAX, cc_mult = 0;
	f_priority_queue max_f_queue;
	vector<node_t> transposed;
	transposed.resize(nodes.size());

	// init
	int64_t idx = 0;
	for(node_t &nd : nodes)
	{
		nd.id = idx++;
		nd.color = 0;
		nd.f = 0;
	}

	// first DFS for finishing time
	for(int64_t i = 0; i < nodes.size(); ++i)
	{
		if(nodes[i].color == 0) {
			dfs_visit(nodes, i, time, cc_min, cc_mult);
		}
	}

	// compute Gt
	for(int64_t i = 0; i < nodes.size(); ++i)
	{
		node_t nd = nodes[i];

		transposed[i].id = nd.id;
		transposed[i].cost = nd.cost;
		transposed[i].color = 0;
		transposed[i].f = nd.f;
		
		for(int64_t j : nd.neighbors) {
			transposed[j].neighbors.push_back(i);
		}

		f_t f_nd;
		f_nd.id = i;
		f_nd.val = nd.f;

		max_f_queue.push(f_nd);
	}

	// apply dfs again on Gt on f-sorted nodes
	time = 0;
	int64_t ccs_cost = 0, ccs_mult = 1;
	f_t current;
	node_t current_nd;
	while(!max_f_queue.empty())
	{	
		current = max_f_queue.top();
		max_f_queue.pop();

		current_nd = transposed[current.id];

		cc_min = INT_MAX;
		cc_mult = 0;
		if(current_nd.color == 0)
		{
			dfs_visit(transposed, current.id, time, cc_min, cc_mult);
			
			ccs_cost += cc_min;
			ccs_mult *= cc_mult;
		}
	}

	cout << ccs_cost << " " << ccs_mult % MAX_WAYS << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t n, m, x, y, i;
	vector<node_t> nodes;

	cin >> n;

	for (i = 0; i < n; ++i)
	{
		cin >> x;

		node_t node;
		node.cost = x;

		nodes.push_back(node);
	}

	cin >> m;

	for(i = 0; i < m; ++i)
	{
		cin >> x >> y;

		nodes[x - 1].neighbors.push_back(y - 1);
	}

	checkposts(nodes);
}