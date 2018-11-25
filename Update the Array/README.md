# Update the Array

## Solution

The naive solution consists in updating all the locations involved in ranges adding the specified value. Then, the algorithm reports the value at the requested position.
However, this approach is O(q * n) because, in the worst case, each range can update all n positions.

An more efficient algorithm could use a Binary Indexed Tree to store such numbers. Each update <l, r, val> is executed by adding val to position l and removing val to position r + 1 of the BIT.
Then, the answer of each query q is the sum up to position q.

## Complexity

Using a BIT, each update operation takes O(2 * log(n)) as we update two locations and each answer to a query takes O(log(n)).
So, the overall complexity is O(u * log(n) + q * log(n)) time using O(n) additional space to store the BIT.
