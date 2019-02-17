#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

int triplets(vector<int> const &items)
{
    vector<int> left_occs(items.size(), 0), right_occs(items.size(), 0);
    int count = 0;
    for (size_t i = 0; i < items.size() - 1; ++i)
        for (size_t j = i + 1; j < items.size(); ++j)
            if (items[i] < items[j])
            {
                right_occs[i]++;
                left_occs[j]++;
            }

    for (size_t i = 1; i < items.size() - 1; ++i)
        count += left_occs[i] * right_occs[i];

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    vector<int> a;

    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << triplets(a) << endl;

    return 0;
}