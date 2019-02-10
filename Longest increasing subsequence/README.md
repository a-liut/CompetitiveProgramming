# Longest increasing subsequence

## Solution

Given a sequence S of numbers, its lis can defined recursively as follows:

$
lis(i) =
  \begin{cases}
    1 + max(lis(j) \ | \ j \in [1, i] \ \land \ S[j] < S[i] )   & \\
    1       & \quad \text {if such j doesn't exists}
  \end{cases}
$

This definition shows the optimal substructure of the problem and its overlapping subproblems, by looking for the previously computed lis values.

The answer is the maximum of these values.

## Complexity

This DP algorithm runs in $O(n^2)$ as computing the maximum for each lis(j) requires $O(n)$. It uses $\Theta(n)$ additional space to store the array for memoization.
