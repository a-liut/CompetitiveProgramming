# Edit Distance

## Solution

The edit distance problem can be solved using a DP algorithm. Let be $s_i$ the prefix of the string s from character 0 to i. Given two strings $a$ and $b$, let $distance(i, j)$ indicates the minimum number of operations needed to transform the prefix $a_i$ in $b_j$.
As operations have cost 1, $distance(i, j)$ can be defined recursively as follows:

$
distance(i, j) =
  \begin{cases}
    j       & \quad i = 0 \\
    i       & \quad j = 0 \\
    distance(i - 1, j - 1)   & a_i = b_j \\
    1 + min\{
        distance(i - 1, j),
        distance(i, j - 1),
        distance(i - 1, j - 1)
    \} & \text{otherwise}
  \end{cases}
$

Assume that we are processing characters $a[i]$ and $b[j]$. If the characters are the same, then the distance is exactly the distance computed with strings one character shorter. Otherwise, we need to compute the minimum value for distance in case we $insert$, $remove$ or $swap$ a character respectively.

The answer will be computed in position distance(i, j).

## Complexity

This algorithm has a running time of $\Theta(|a||b|)$ and requires $\Theta(|a||b|)$ additional space to store the DP table for memoization.