# Wilbur and Array

## Solution

The answer can be found simply scanning the numbers from left to right summing up the differences between the current number and its predecessor.

## Complexity

The algorithm scans the sequence of numbers only once performing constant time operations for each item. Therefore, its time complexity is $\Theta(n)$.

The solution found by this greedy algorithm is optimal.

Consider the first element of the array $b$, that is $b_i$ and let $L$ be the rest of the sequence of numbers. Starting from $a_i = 0$, Wilbur can perform $abs(a_i - b_i)$ add or subtract operation in order to get $a_i = b_i$. Then, when algorithm moves to the next element, item $a_i$ is no more updated by any next operation.

So, $abs(a_i - b_i)$ is the minimal number of operations that Wilbur must perform, thus it is included in the optimal solution. Inductively, the algorithm gives the optimal solution for $L$ and the sum of the two is the optimal solution.