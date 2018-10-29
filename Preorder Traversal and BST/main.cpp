#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MIN -1

bool isBSTTraversal(vector<int> &values)
{
    int last = MIN;
    std::stack<int> s;

    s.push(values.front());

    vector<int>::iterator it = values.begin() + 1;
    while (it != values.end())
    {
        if (*it < s.top())
        {
            if (*it < last)
                return false;

            s.push(*it);
        }
        else
        {
            while (!s.empty() && *it > s.top())
            {
                last = s.top();
                s.pop();
            }

            s.push(last);
            s.push(*it);
        }

        it++;
    }

    return true;
}

int main()
{
    int T, n, x;
    vector<int> values;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        for (int e = 0; e < n; e++)
        {
            cin >> x;
            values.push_back(x);
        }

        cout << isBSTTraversal(values) << endl;

        values.clear();
    }

    return 0;
}