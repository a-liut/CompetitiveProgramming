# Circular RMQ

## Solution

RMQ problem can be solved efficiently using a segment tree whose internal nodes contain the minimum value in their respective segments.
The algorithm use the fact that a circular segment is composed by two subsegments: let \[lf, rg\] be a circular segment (i.e. $lf > rg$) then the two subqueries are \[0, rg\] and \[lf, |elements| - 1\]. So, to answer the RMQ query, we just perform those two subqueries and take the minimum from the two.
A similar approach is used to update the segment tree using a circular segment.

To make the rmq and update operations faster, the segment tree uses a lazy tree.

## Complexity

The complexity of both operations are O(log(n)) for normal segments and O(2 * log(n)) = O(log(n)) for circular ones as the algorithm perform two operations instead of one to query or update the tree.