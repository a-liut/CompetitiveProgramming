# Shift the string

## Solution

Based on <https://discuss.codechef.com/questions/48550/tashift-editorial>.

Given the two strings A and B, the solution can be found applying KMP searching for the substrings of B in the composed string $S = B.B$. S contains all possible shifts that can be done on B.

Applying KMP we look for the pattern A in S. The algorithm maintain the largest match for the pattern, and the answer can be computed subtracting from the index of such end match ends the number of matched characters of the pattern, giving the number of shifts needed.

## Complexity

The algorithm runs in $O(|A| + 2|B|)$ using $O(|A|)$ of additional space.