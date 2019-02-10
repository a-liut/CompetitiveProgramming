# Minimum number of jumps

## Solution

The problem has an optimal substructure: Given a sequence S of numbers, let jumps(i) the minimum number of jumps to move to position i. It can be recursively defined as follows:

$
jumps(i) =
  \begin{cases}
    min\{jumps(j) \ | \ j \in [1, i) \land jumps(j) \geq 0 \land j + S[j] \geq i \} + 1   & \\
    -1 & \text{if no such j exists}
  \end{cases}
$

jumps(i) can be computed by taking the minimum number of jumps needed to move to a position where we can reach position i with 1 additional jump. The position should also be reachable ($jumps(j) \geq 0$, indeed).

## Complexity

This DP algorithm has a running time of $O(n^2)$ because for each position it computes the position with minimum jumps to reach the current one in linear time. It uses also $\Theta(n)$ additional space to store the array for memoization of the values.