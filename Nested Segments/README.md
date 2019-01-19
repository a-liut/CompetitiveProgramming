# Nested Segments

## Solution
The algorithm starts mapping the values of the input array into values that range in \[0-1\]. This reduces the size of the numbers and allows us to use less memory for maintaining the BIT.

To check that, say $a$, contains another segment, say $b$, we need to check that $l_a < l_b$ and $r_b < r_a$. So, the next step of the algorithm is to sort ranges according to their left border. In this way, the condition $l_a < l_b$ is always satisfied while scanning them.

For each segment $a$, the algorithm stores in a BIT +1 at position $r_a$. The number of segments that the current segment contains is given by $Sum(r_a - 1)$. Only segments that are placed on the right of the current segment are considered in the sum, because of the sorting.

## Complexity

Let $n$ be the number of input ranges, then the algorithm takes:

1. $\Theta(n) + O(n log n) + \Theta(n log n) = \Theta(n log n)$ to map the ranges.
2. $\Theta(n log n)$ to scan the ranges, updating the BIT and computing the prefix sum.

So, the overall complexity of the algorithm is $\Theta(n log n)$ time using $O(n)$ additional space to store the BIT and vectors for the mapping and storing the results.