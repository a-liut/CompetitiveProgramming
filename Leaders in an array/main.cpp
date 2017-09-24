#include <stdio.h>

// this function will calculate the leaders and store
// them in res array.
void leaders(int a[], int n, int res[], int* resDim) {
	// minimum value according to constraint 0 <= a[i] <= 100, for each 0 <= i <= n
    int max = -1;

    *resDim = 0;

    // scan the array starting from last element
    // storing the maximum
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] > max) {
        	// a[i] is a leader, so store it in the result array
            res[*resDim] = a[i];
            max = a[i];
            *resDim = *resDim + 1;
        }
    }
}

int main() {
    // max array size according to problem constraints
    const int SIZE = 100;
    int tests, n, a[SIZE], res[SIZE], resDim;

    // read tests number
    scanf("%d", &tests);

    for(int i = 0; i < tests; i++) {
        // read array size
        scanf("%d", &n);

        // fill array
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        // calculate leaders
        leaders(a, n, res, &resDim);

        // print result
        printf("%d", res[--resDim]);
        for(int k = resDim - 1; k >= 0; k--) {
            printf(" %d", res[k]);
        }
        printf("\n");
    }

    return 0;
}