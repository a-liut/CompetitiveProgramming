# Inversion Count

## Solution

Based on <https://www.geeksforgeeks.org/counting-inversions/>

The number of inversions of a given array A can be found performing a modified version of Merge Sort. In fact, the inversion is what Merge Sort recognize when place elements in the result array in each recursive step.

At each step, the number of inversions can be computed as

$
inv(i, j) =
  \begin{cases}
    0       & i == j \\
    inv(i, mid) + inv(mid + 1, j) + merge(i, j)   & \text{otherwise}
  \end{cases}
$

with $mid = \frac{i + j}{2}$.

The recursive calls to $inv$ computes the answer for the subproblems having a smaller array to check. We need to add the inversions found during the merge phase.

Let $a_i$ and $b_i$ the current processed elements of the left side and right side of the current interval respectively. Then, if $a_i > b_i$, the elements after $a_i$ are greater than $b_i$, thus $(b_i, a_j)$ is an inversion with i < j < mid because element $b_i$ will be placed before any $a_j$ element.

## Complexity

The algorithm is a variant of MergeSort and takes $O(nlogn)$ using $O(n)$ additional space to store temporary merge result.