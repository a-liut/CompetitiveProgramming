# X Total Shapes

## Solution

This problem can be solved by building a graph using as nodes the 'X's found on the input and applying the DSF to each node. In other words, then number of X shapes is the number of connected components in the graph built from 'X's.
First of all, the algorithm build the graph by assigning a unique id to each 'X' found while reading the input.
Then, it apply DFS to each of them to find how many connected components there are in the graph.

## Complexity

The algorithm takes $\Theta(n^2)$ time to perform the DFS due to the fact that the graph is implemented using an adjacency matrix. So, it uses also $\Theta(n^2)$ space to store the adjacency matrix and the one for storing the 'visited' flag for each node.