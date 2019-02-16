#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 100001

using namespace std;

struct query_t
{
    int pos_l, pos_r, k;
    size_t id;
};

vector<vector<int>> tree;
vector<query_t> queries;
vector<int> color, occurrences, occurrences_counter, answers, start_times, end_times, linear;

void dfs(int u, int parent, int &time)
{
    start_times[u] = ++time;
    linear[time] = color[u];
    
    for (int &node : tree[u]) if (node != parent) dfs(node, u, time);

    end_times[u] = time;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, t, bucket_size, time = 0;
    cin >> n >> t;

    bucket_size = (int)sqrt(n);

    color.resize(n + 1);
    tree.resize(n + 1);
    queries.resize(t);
    answers.resize(t + 1, 0);
    occurrences.resize(MAX_N, 0);
    occurrences_counter.resize(MAX_N, 0);
    start_times.resize(n + 1, 0);
    end_times.resize(n + 1, 0);
    linear.resize(n + 1, 0);

    for (size_t i = 0; i < n; i++)
    {
        cin >> color[i];
    }

    int u, v;
    for (size_t i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    dfs(0, -1, time);

    for (size_t i = 0; i < t; ++i)
    {
        int v, k;
        cin >> v >> k;

        queries[i] = query_t{start_times[v - 1], end_times[v - 1], k, i};
    }

    auto cmp = [&](query_t const &a, query_t const &b) -> bool {
        int left1 = a.pos_l / bucket_size;
        int left2 = b.pos_l / bucket_size;
        
        return (left1 != left2) ? (a.pos_l < b.pos_l) : (a.pos_r < b.pos_r);
    };

    // Sort queries
    sort(queries.begin(), queries.end(), cmp);

    // Apply Mo's
    int current_l = queries[0].pos_l;
    int current_r = current_l - 1;

    for (size_t i = 0; i < t; ++i)
    {
        while (current_l > queries[i].pos_l)
        {
            current_l--;
            occurrences[linear[current_l]]++;
            occurrences_counter[occurrences[linear[current_l]]]++;
        }

        while (current_r < queries[i].pos_r)
        {
            current_r++;

            occurrences[linear[current_r]]++;
            occurrences_counter[occurrences[linear[current_r]]]++;
        }

        while (current_l < queries[i].pos_l)
        {
            occurrences_counter[occurrences[linear[current_l]]]--;
            occurrences[linear[current_l]]--;

            current_l++;
        }

        while (current_r > queries[i].pos_r)
        {

            occurrences_counter[occurrences[linear[current_r]]]--;
            occurrences[linear[current_r]]--;

            current_r--;
        }

        answers[queries[i].id] = occurrences_counter[queries[i].k];
    }

    for (size_t i = 0; i < t; ++i)
    {
        cout << answers[i] << endl;
    }

    return 0;
}