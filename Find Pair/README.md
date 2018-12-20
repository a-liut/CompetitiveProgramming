# Find Pair

## Solution

We can find the correct pair by sorting the sequence of numbers and computing the indexes of the two elements of the pair.
The first index can be computed as x(k, n) = (k - 1) / n.

To compute the second index we must consider the case of duplicated keys: in fact, pairs composed with those duplicated keys will be listed before the next value.
Thus, the second index can be computed as y(k, n, l, r) = ((k - 1) - l * n) / r where l is the number of elements lower than a\[x\] and r is the number of elements equal to a\[x\].

## Complexity

The algorithm performs two main steps:

- sort the array to establish a precise order between keys in O(nlog(n))
- find the value of l and r by scanning the array until the value of a\[x\]. The worst case is whenever x points to the last element of the array, thus this scan takes O(n)

The algorithm takes O(nlog(n) + n) = O(nlog(n)) time and uses O(1) additional space, storing only constants to achieve the goal.