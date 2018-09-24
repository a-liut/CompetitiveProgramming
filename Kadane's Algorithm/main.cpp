#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kadane(vector<int> &items)
{
    int current = *items.begin(), absoluteMax = *items.begin();

    for (vector<int>::iterator it = items.begin() + 1; it < items.end(); it++)
    {
        current = max(current + *it, *it);

        absoluteMax = max(current, absoluteMax);
    }

    return absoluteMax;
}

int main()
{
    int T, N, x;
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

        int sum = kadane(items);

        cout << sum << endl;

        items.clear();
    }
}