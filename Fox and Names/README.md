# Fox and Names

## Solution

The new order between the characters can be established by putting some precedence constraints on them. Precedences between characters can be represented by a DAG and the new ordering obtained computing the topological sort of it.
The algorithm scans the list of words finding the first difference between each pair of subsequent word. Let $a$ and $b$ be the current two strings and $i$ be the position in which the first difference occurs. Then, to impose an ordering between them, we add the edge $(a_i, b_i)$, i.e. a_i must precede b.

If no such position exists, one of the two strings is a prefix of the other. If the previous string in the sequence is less than the next, then the edge that will be created is a self-loop, and it can be discarded as it does not produce any change in the final order. Otherwise, the algorithm must report a failure, as the ordering will be not valid.

Then, the algorithm computes the topological sort by applying DFS starting from nodes whose in-degree is not 0. At the end of the DFS, all nodes should be reached and the topological sort print as the new ordering. If there are some nodes that are not printed by the algorithm, it must be the case that the graph contains a loop, thus it is not a DAG and the answer cannot be found, so a negative answer is produced.

## Complexity

Let:

- $n$ be the number of the given strings
- $m$ be the number of letters in the used alphabet
- $k$ be the maximum size of a string

The algorithm scans all the strings in $O(nk)$ to build the graph. Then it requires $O(m + n)$ to apply the DFS as the algorithm adds exactly $n - 1$ edges to the graph.

Thus, its overall time complexity is $O(nk + m)$ using $\Theta(m^2)$ additional space to store the adjacency matrix of the graph.