#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_water(vector<int> a)
{
    int n = a.size();
    int rmax[n], lmax[n], max, i, water = 0;

    max = n - 1;
    rmax[max] = 0;
    // 1st iteration to obtain right maximums
    for (i = n - 2; i >= 0; i--)
    {
        // store right maximum for column i
        rmax[i] = a[max];

        if (a[i] >= a[max])
        {
            // update maximum
            max = i;
        }
    }

    // 2nd scan to obtain left maximums
    max = 0;
    lmax[max] = 0;
    for (i = 0; i < n; i++)
    {
        // store left maximum for column i
        lmax[i] = a[max];
        if (a[i] >= a[max])
        {
            // update minimum
            max = i;
        }
    }

    // 3rd scan to calculate water
    for (i = 0; i < n; i++)
    {
        water = water + std::max(
                            std::min(rmax[i], lmax[i]) - a[i],
                            0);
    }
    return water;
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

        cout << calculate_water(items) << endl;

        items.clear();
    }
}