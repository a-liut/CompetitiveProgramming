# isBipartite

## Solution

Checking if a graph is bipartite is equivalent to find a 2-coloring of it. A 2-coloring can be found by processing all the nodes and assigning a color to them and their neighbor.

The algorithm processes all nodes one by one, and for each node, it performs the following operations:

1. Check whether the node has a self-loop. In this case, the graph cannot be a bipartite one
2. For all of the node's neighbor, check if they can be colored using a different color than the current one. If the node is already colored with a different color than the correct one, then the graph is not bipartite. Otherwise, the algorithm assigns the color to the neighbor.

## Complexity

The algorithm performs a linear scan of the nodes, which requires $\Theta(V)$ and for each node scans all their neighbor. As the graph is represented by an adjacency matrix, coloring the neighbors of a node requires $\Theta(V)$ as well.

Thus, the overall worst case complexity of the algorithm is $\Theta(V^2)$ using $\Theta(V)$ additional space to store colors of the vertices.