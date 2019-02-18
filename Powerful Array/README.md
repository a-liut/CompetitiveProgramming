# Powerful Array

## Solution

This problem can be solved using Mo's algorithm. It uses two additional arrays, one to store the occurrencies of any element in the array and the other to store the answers of the queries. This last part allows the algorithm avoid sorting the queries to maintain the original order of the queries.

When adding or removing an element to the current window, the difference to be added or removed to the current query answer can be computed as $2 \times K * s + s$ (see <https://gist.github.com/CharlyGaleana/b7df36b42cec6a4ffb49>).

## Complexity

Let $n$ be the number of elements in the input array and $t$ be the number of queries. The algorithm performs the following steps:

- Sort the queries according either to their left end, whether they fall in different buckets, or their right end otherwise. This operation takes $O(nlogn)$.
- Scan the queries and move the pointers of the current interval (Mo's algorithm). This operation takes $O(t\sqrt{n} + n\sqrt{n})$.
- Print the answer of each query. This operation takes $\Theta(t)$.

The overall complexity of the algorithm is dominated by the querying operation, thus the algorithm takes $O(t\sqrt{n} + n\sqrt{n})$ and uses $O(n + t)$ additional space to store the auxiliary structures.