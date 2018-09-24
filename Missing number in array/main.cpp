#include <iostream>
#include <vector>

using namespace std;

int missing_number(vector<int> &items)
{
    int n = items.size() + 1;
    int sum = 0;
    int total = (n * (n + 1)) / 2;

    for (int it : items)
    {
        sum += it;
    }
    
    return total - sum;
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

        for (int k = 0; k < N - 1; k++)
        {
            cin >> x;
            items.push_back(x);
        }

        int sum = missing_number(items);

        cout << sum << endl;

        items.clear();
    }
}