# Minimum Spanning Tree

## Solution

The minimum spanning tree of the given graph can be found applying the Kruskal's algorithm and storing the current weight sum of the edges added to the tree.

The algorithm uses the vector nodes to store node pointers to implement the disjoint data structure needed by Kruskal's algorithm.

## Complexity

The disjoint data structure used by Kruskal's algorithm uses both union by rank and path compression optimization techniques.
Therefore, the running time of Kruskal's algorithm is $O(|E|log(|V))$ using $O(n)$ additional space to store node node pointers.