# 0-1 Knapsack

## Solution

The 0-1 Knapsack problem can be solved using a Dynamic Programming algorithm.

For each item, the algorithm has to decide whether to add or not the current item into the knapsack. If the item is not added, then the solution is the same as we have one less item with the same knapsack size. Otherwise, the solution is value with one less item but with knapsack with less space available.

The algorithm uses a table where each item is defined as follows:

$
T(i, j) =
  \begin{cases}
    0       & \quad i = 0 \ \text{or} \ j = 0 \\
    max(T(i - 1, j), T[i - 1, j - w_i]) + v_i   & \text{otherwise}
  \end{cases}
$

Each location of the table stores either 0, for base cases, or the maximum value between the value achieved by taking the item or not.

## Complexity

This algorithm runs in $\Theta(n \times W)$ time as it processes each element once checking it with all possible knapsack sizes. It uses $\Theta(n \times W)$ additional space to store the DP table.
