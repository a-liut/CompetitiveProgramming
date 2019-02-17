# Triplets

## Solution

The algorithm implements an $O(n^2)$ solution.

Let $a$ be the given sequence. The algorithm builds two arrays:

* $lo[i]$ stores the number of times that the element $a_j$ with $i < j < n$ is greater that the current element $a_i$.

* $ro[i]$ stores the number of times that the element $a_i$ is less than one of its successor $a_j$.

Thus, for each position $i$, the number of triplets that satisfy the problem constraint is computed as $lo[i] * ro[i]$.

So, the answer is given by $\sum_{i = 0}^{n} lo[i] * ro[i]$.

## Complexity

The running time of this solution is $O(n^2)$ using $O(1)$ additional space.