# Checkposts

## Solution

A possible solution to this problem is to represent junctions as nodes and connection between junctions as edges of a graph G. Each node stores the cost of building a station on that junction.
Then, the algorithm computes the strongly connected components of G to get groups of junctions that are reachable each other. Inside a component, the junctions with the lowest building cost will be the one chosen for building the station.

The algorithm modifies the second DFS performed on $G^T$: each component traversal computes also the minimum cost for building a station in that component and the number of nodes with that value.

Let $minCost_i$ be the minimum building cost of the component $i$ and $minOccurrences_i$ be the number of occurrences of a node with the minimum building cost.
The answer can be computed as 

$\sum_{C \in SCC} minCost_C$ 

to compute the minimum cost for building the stations and 

$\prod_{C \in SCC} minOccurrences_C$

to compute the number of ways the buildings can be built.

## Complexity

Let $n$ be the number of junctions and $m$ the number of connections between them. The algorithm takes:

- $\Theta(n)$ to initialize the nodes for the DFSs.
- $O(n + m)$ to run DFSs and to compute $G^T$.

Therefore, the overall time complexity of the algorithm is $O(n + m)$ using additional O(n + m) additional space to store the graph and support arrays.