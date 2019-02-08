# Longest Common Subsequence

## Solution

Finding the length of the LCS of two given strings is an optimization problem and we can solve it applying Dynamic Programming.

Given two strings $a$ and $b$, let $a_i$ and $b_i$ be respectively the prefix of string $a$ and $b$ of length $i$, and let $lcs(s_1, s_2)$ be the length of the lcs between strings $s_2$ and $s_1$.

We can define recursively the optimal solution for $lcs$ as follows:

$
lcs(a_i, b_j) =
  \begin{cases}
    0       & \quad i = 0 \ \text{or} \ j = 0 \\
    max(lcs(a_{i-1}, b_j), lcs(a_i, b_{j-1}))       & \quad a[i] \neq b[i] \\
    lcs(a_{i-1}, b_{j-1}) + 1  & \text{otherwise}
  \end{cases}
$

Assume that we have already solved the subproblems $lcs(a_{i-1}, b_j)$, $lcs(a_i, b_{j-1})$ and $lcs(a_{i-1}, b_{j-1})$.
We distinguish three cases:

1. If one of the two strings is the empty string, then the answer is trivially $0$.
2. If $a[i] \neq b[i]$, we can't append the current character to the answer, so we maintain the maximum of the two lcs length found for the substrings by now.
3. if $a[i] = b[i]$, then we can append the characted to the lcs found in both of the substrings. Thus, we add one to the previous computed solution.

The algorithm uses a table to store the previous results.

## Complexity

The algorithm runs in $\Theta(|a| \times |b|)$, as it uses the table to not recompute previous values while scanning the strings.
It uses $\Theta(|a| \times |b|)$ extra space to store the table.