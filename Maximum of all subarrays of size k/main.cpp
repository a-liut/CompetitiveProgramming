#include <stdio.h>
#include <algorithm>

// this method return the sum of the maximum sum of the contiguous sub-array of array a
int sum_of_max_sub_array(int a[], int n)
{
    // start with the first sub-array, that is just the first element
    int current = a[0], max = a[0];

    for(int i = 1; i < n; i++)
    {
        // the optimal sub-array at position i has the optimal sub-array
        // found at position i-1 as a prefix or not if the current element is
        // a better sub-array.
        current = std::max(current + a[i], a[i]);

        // the absolute maximum is the current maximum found or a previous one.
        max = std::max(current, max);
    }

    return current;
}

int main()
{
    // array size according problem constraints
    const int SIZE = 1000;
    int T = 0, N = 0, a[SIZE];

    // read test number
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        // read test array size
        scanf("%d", &N);

        for(int j = 0; j < N; j++)
        {
            // fill the array
            scanf("%d", &a[j]);
        }

        // print the current solution
        printf("%d\n", sum_of_max_sub_array(a, N));
    }

    return 0;
}