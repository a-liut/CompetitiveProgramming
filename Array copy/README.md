# Array Copy

## Solution

Based on <https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text23012018.pdf>

To reduce the complexity of copy operation, we can fake it storing the triple $(x, y, k)$ that updates a certain location in B and use it to access directly to A instead of b. If no such kind of triple exists, then the algorithm accesses directly to array B.

Each $copy(x, y, k)$ operation has an id, which is the index of the array that stores all the queries. The algorithm uses a segment tree whose nodes contains the id of the last query that modifies a certain range of data. To do so, the algortithm puts the id of the query into each node that represents a range that totally overlaps the copy range.

The $access(i)$ operation starts from the i-th leaf and climb the tree up returning the maximum query id found till the root node. The maximum id refers to the last copy operation that updates the range. If no copy operation updates the i-th position of B, then $B[i]$ is reported, otherwise the algorithm report the element $A[i - q.y + q.x]$ where $x$ is the query with maximum id found.

## Complexity

Using the segment tree that reuqires $O(n)$ to be built, both copy and access operations run in $O(log n)$.
The overall algorithm complexity is $O(n + logn)$ time using $O(n)$ additional space to store the segment tree.