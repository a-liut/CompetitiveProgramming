# Learning Languages

## Solution

The problem can be solved by representing employees as nodes of a graph where edges connect employees that have a language in common.

Given such a graph G, the minimum number of languages that the employees should learn can be computed by finding the number of connected components. In fact, each connected component of G represents a group of employees that can speak with each other in the group. To let all the employees talk with each other, the algorithm has to connect those components with $|components| - 1$ arcs. In this way, there is a path connecting all employees to each other employee.

In order to apply the algorithm, at least one employee must speak a language. In case no employee speaks any language, the answer is exactly $|components|$, because the algorithm adds a language to one employee to let the later connection possible.

## Complexity

Let $n$ be the number of employees and $m$ the number of languages.
The algorithm performs two main steps:

1. Graph building by connecting employees that share a common language. This is done while reading the input in $O(n * m)$ time.
2. Connected components discovering by applying two depth-first searches taking $O(n^2)$ each.

Therefore, the overall algorithm time complexity is $O(n^2)$ using $O(n^2)$ additional space to store the adjacency matrix of the graph, the priority queue, and the color array to support DFS applications.
