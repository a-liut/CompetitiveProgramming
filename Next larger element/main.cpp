#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

stack<int> next_larger_element(vector<int> &items)
{
    stack<int> result;
    deque<int> q;

    int max = -1;
    for (vector<int>::reverse_iterator it = items.rbegin(); it != items.rend(); it++)
    {
        if (q.empty())
        {
            q.push_back(*it);
            result.push(-1);
        }
        else
        {
            // Remove elements that are smaller than the current element
            while (!q.empty() && q.back() < *it)
            {
                q.pop_back();
            }

            if (!q.empty())
            {
                // q.back() is the next larger element for the current element
                result.push(q.back());
            }
            else
            {
                // No larger element for the current one
                result.push(-1);
            }
            
            q.push_back(*it);
        }
    }

    return result;
}

int main()
{
    int T, N, k, x;
    vector<int> items;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        items.reserve(N);

        for (int k = 0; k < N; k++)
        {
            cin >> x;
            items.push_back(x);
        }

        stack<int> result = next_larger_element(items);

        int res;
        while (!result.empty())
        {
            res = result.top();
            result.pop();
            cout << res << " ";
        }
        cout << endl;

        items.clear();
    }
}