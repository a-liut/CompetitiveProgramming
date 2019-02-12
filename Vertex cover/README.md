# Vertex cover

## Solution

The solution is a combination of DP and tree traversal.

Each node has two possibilities: either to be part of the solution or not. Thus, the algorithm uses a table $T$ of size $n \times 2$ where $T(i, 0)$ and $T(i, 1)$ are the number of nodes in the vertex cover in which node $i$ is added or not in the solution respectively.

The algorithm applies a post-order DFS visit starting from a dummy node $0$. Let T be the table. The algorithm processes a node $u$ as follows:

- If $u$ is a leaf, which is a base case, then $T(u, 0) = 0$ and $T(u, 1) = 1$.
- If $u$ is not a leaf, then the algorithm traverse its children first, computing their values in T. Then, $T(u, 0) = \sum_{v \in N(u)}{T(v, 1)}$ and $T(u, 1) = \sum_{v \in N(u)}{min\{T(v, 0), T(v, 1)\}}$

The answer is $min\{T(1, 0), T(1, 1)\}$, as this location contains the size of the minimum vertex cover found for the root node.

## Complexity

The algorithm runs in $O(|V|)$ as the visit of the tree dominates the running time of the algorithm using $\Theta(|V|)$ additional space to store the table.