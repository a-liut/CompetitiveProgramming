#include <iostream>
#include <vector>

using namespace std;

int64_t merge(vector<int64_t> &arr, vector<int64_t> &temp, int64_t left, int64_t mid, int64_t right)
{
    int64_t i = left, j = mid, k = left, count = 0;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            count += mid - i; // #inversions = (mid - i)
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

int64_t _inversions(vector<int64_t> &items, vector<int64_t> &temp, int64_t start, int64_t end)
{
    if (start >= end)
    {
        return 0;
    }

    int64_t c = (start + end) / 2;
    int64_t linv = _inversions(items, temp, start, c),
            rinv = _inversions(items, temp, c + 1, end);

    return merge(items, temp, start, c + 1, end) + linv + rinv;
}

int64_t inversions(vector<int64_t> &items)
{
    vector<int64_t> temp(items);
    return _inversions(items, temp, 0, items.size() - 1);
}

int main()
{
    int64_t T, n, x;

    cin >> T;

    vector<int64_t> items;

    for (int64_t i = 0; i < T; i++)
    {
        cin >> n;

        items.reserve(n);

        for (int64_t j = 0; j < n; j++)
        {
            cin >> x;
            items.push_back(x);
        }

        cout << inversions(items) << endl;

        items.clear();
    }
}