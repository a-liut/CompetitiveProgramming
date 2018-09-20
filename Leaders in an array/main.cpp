#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_ELEM_NO = 100;

void leaders(vector<int> &items, stack<int> &result)
{
    int max = *items.rbegin();
    result.push(max);

    for (vector<int>::reverse_iterator it = items.rbegin() + 1; it != items.rend(); ++it)
    {
        if (*it >= max)
        {
            result.push(*it);
            max = *it;
        }
    }
}

int main()
{
    int T, N, x;
    vector<int> items;
    stack<int> results;

    cin >> T;

    items.reserve(MAX_ELEM_NO);

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        for (int k = 0; k < N; k++)
        {
            cin >> x;
            items.push_back(x);
        }

        leaders(items, results);

        while (!results.empty())
        {
            cout << results.top() << " ";
            results.pop();
        }

        cout << endl;

        items.clear();
    }
}