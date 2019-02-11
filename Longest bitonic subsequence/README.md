# Longest bitonic subsequence

## Solution

We can observe that the longest bitonic sequence is the composition of two subsequences, the LIS and the LDS.
Thus, to find the answer we first compute for each position the length of the LIS and LDS by applying the algorithm for LIS from right to left for the former case and from right to left for the latter case.

Then, we compose the length of the the bitonic sequence as $LIS[i] + LIS[n - i] - 1$. The answer is the maximum of these lengths.

## Complexity

The algorithm complexity is dominated by the complexity of the algorithm for finding the LIS, which requires $O(nlogn)$ time.

Therefore, the running time of the algorithm is $O(nlogn)$ and it requires $O(n)$ additional space to store the values for LIS and LDS.