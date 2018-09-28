#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void sum_of_max_sub_array(vector<int> const &items, int k, vector<int> &results)
{
    results.clear();
    deque<int> maxs;

    for (int i = 0; i < items.size(); i++)
    {

        if (!maxs.empty() && maxs.front() < i - k + 1)
        {
            maxs.pop_front();
        }

        int current = items[i];

        if (!maxs.empty() && current > items[maxs.front()])
        {
            maxs.clear();
            maxs.push_back(i);
        }
        else
        {
            while (!maxs.empty() && items[maxs.back()] < current)
            {
                maxs.pop_back();
            }

            maxs.push_back(i);
        }

        if (i >= k - 1)
        {
            results.push_back(items[maxs.front()]);
        }
    }
}

int main()
{
    int T, N, k, x;
    vector<int> items;
    vector<int> result;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cin >> k;

        items.reserve(N);

        for (int k = 0; k < N; k++)
        {
            cin >> x;
            items.push_back(x);
        }

        sum_of_max_sub_array(items, k, result);

        for (int res : result)
        {
            cout << res << " ";
        }
        cout << endl;

        items.clear();
    }
}