# Tree and Queries

## Solution

The solution can be found by applying Mo's algorithm. Given the tree, the algorithm flatten in using a pre-order DFS traversal storing the starting and the finishing times of each node. These values indicate at what position each node subtree starts and ends respectively. For each query, a pair of indices is produced using those values.

Each time a node color is added or removed to the current window, the algorithm updates the number of occurrencies of that color. Furthermore, the algorithm stores the number of different color found for each possible value of k. Thus the answer is at the requested position by the query.

## Complexity

The running time of this algorithm is dominated by the order we process the query with, which is $O(m\sqrt{n} + n\sqrt{n})$ using $O(n)$ additional space.