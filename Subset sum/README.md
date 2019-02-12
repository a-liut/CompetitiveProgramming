# Subset sum

## Solution

Given a set $S$ of values, we need to find $S_1 \subset S$ and $S_2 \subset S$ such that:
- $S_1 \cap S_2 = \emptyset$
- $S_1 \cup S_2 = S$
- $\sum_{x \in S_1} x = \sum_{x \in S_2} x$

Let $sum(S) = \sum_{x \in S} x$. Those properties implies that $sum(S_1) = sum(S_2) = \frac{S}{2}$.

The algorithm checks first if the sum of the elements of $S$ can be divided by two, otherwise it reports NO.

If the sum can be divided by two, it apply a DP strategy:
Let $T(i, j)$ be true if and only if there is a subset of the first $i$ elements that sums exactly to $j$, false otherwise, and $V = \frac{S}{2}$. For each processed element $s_i$, it could be taken into the solution or discarded.

Thus, the problem presents an optimal substructure and the solution is defined recursively as follows:

$
T(i, j) =
  \begin{cases}
    false       & \quad i = 0 \land j \neq 0 \\
    true       & \quad j = 0 \\
    T(i - 1, j - v_i) \ \lor \ T(i - 1, j)  & \quad otherwise
  \end{cases}
$

The algorithm uses a matrix of $n \times V$ for memoization and the answer will be stored in position $T(n, V)$.

## Complexity

This algorithm has a running time of $O(nV)$ using $\Theta(nV)$ additional space for the table.