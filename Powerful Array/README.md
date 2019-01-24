# Powerful Array

## Solution

This problem can be solved using Mo's algorithm. It uses two additional arrays, one to store the occurrencies of any element in the array and the other to store the answers of the queries. This last part allows the algorithm avoid sorting the queries to maintain the original order of the queries.

The functions add and remove are defined as follows:

- ADD: Adds an element into the solution. The algorithm computes the difference between the old power of the element and the new power and add it to the current solution. Then, the number of occurrencies of the element is incremented.
- REMOVE: Removes an element from the solution. It computes, similarly to ADD, the difference of the two powers and update the current answer. Then, the number of occurrencies of the current element is decreased.

## Complexity

Let $n$ be the number of elements in the input array and $t$ be the number of queries. The algorithm performs the following steps:

- Sort the queries according either to their left end, whether they fall in different buckets, or their right end otherwise. This operation takes $O(nlogn)$.
- Scan the queries and move the pointers of the current interval (Mo's algorithm). This operation takes $O(t\sqrt{n} + n\sqrt{n})$.
- Print the answer of each query. This operation takes $\Theta(t)$.

The overall complexity of the algorithm is dominated by the querying operation, thus the algorithm takes $O(t\sqrt{n} + n\sqrt{n})$ and uses $O(n + t)$ additional space to store the auxiliary structures.