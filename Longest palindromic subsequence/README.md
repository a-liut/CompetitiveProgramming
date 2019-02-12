# Longest palindromic subsequence

## Solution

The LPS of a string can be found applying DP.
Given a string $S$, let $LPS(i, j)$ be the longest palindromic subsequence found in the interval $[i, j]$ of $S$.

Consider two indices $i$ and $j$. We can observe that we can extend the palindromic subsequence whether $S[i] = S[j]$. Otherwise, the longest palindromic subsequence is the one that we get by removing one character from the left and one from the right and taking the maximum of the two.

Therefore, we can use the following recurrence to build the DP table:

$
LPS(i, j) =
  \begin{cases}
    0       & \quad i > j \\
    1       & \quad i = j \\
    2 + LPS(i + 1, j - 1)   & S[i] = S[j] \\
    max\{LPS(i + 1, j), LPS(i, j-1)\}   & \text{otherwise} \\
  \end{cases}
$

Using this recurrence for the solution, the resulting DP matrix will be upper triangular. Thus, the algorithm can fill only that part.

Moreover, to compute correctly the LPS for each position we need to compute first the values along the diagonal and moving upwards.

Then, the solution can be found in position $LPS(1, |S|)$ which indicates the length of the LPS of the whole string.

## Complexity

The running time of the algorithm is $O(\frac{|S|^2}{2}) = O(|S|^2)$ using $\Theta(|S|^2)$ additional space. 