#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int64_t, size_t> int_pair;

void two_heaps(vector<int_pair> &sequence)
{
    int64_t n = sequence.size();
    vector<int64_t> heaps(n);

    sort(sequence.begin(), sequence.end());

    bool first_occ = true;
    int64_t d_heap[3];
    d_heap[1] = 0;
    d_heap[2] = 0;

    for (size_t i = 1; i < n; ++i)
    {
        if (sequence[i].first == sequence[i - 1].first)
        {
            if (first_occ)
            {
                heaps[sequence[i - 1].second] = 1;
                heaps[sequence[i].second] = 2;
                d_heap[1]++;
                d_heap[2]++;
                first_occ = false;
            }
            continue;
        }
        if (first_occ)
        {
            heaps[sequence[i - 1].second] = (d_heap[1] > d_heap[2]) + 1;
            d_heap[heaps[sequence[i - 1].second]]++;
        }
        first_occ = true;
    }

    if (first_occ and sequence[n - 1] != sequence[n - 2])
    {
        heaps[sequence[n - 1].second] = (d_heap[1] > d_heap[2]) + 1;
        d_heap[heaps[sequence[n - 1].second]]++;
    }

    cout << d_heap[1] * d_heap[2] << endl;

    for (auto x : heaps)
    {
        if (x == 0)
        {
            x = (d_heap[1] > d_heap[2]) + 1;
            d_heap[x]++;
        }
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    size_t n;
    cin >> n;
    n = 2 * n;

    vector<int_pair> sequence(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> sequence[i].first;
        sequence[i].second = i;
    }

    two_heaps(sequence);

    return 0;
}