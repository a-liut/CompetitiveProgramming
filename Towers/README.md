# Towers

## Solution

Given a multiset S containing only natural numbers, finding the height of the largest tower and the number of towers correspond respectively to find the number wich appers more times in S and the number of distinct values in S.

The tower method prints the height of the largest tower and the number of towers using a vector to store them.

The solution is made by two phases: first sort the vector in descending order. Doing so, equals elements are contiguous and this property simplifies the algorithm and a single scan of the array is needed.

Given the vector v, we have two possible cases for the element in position i:

* a[i] is equals to the last seen value: in this case, just increase the number of occurencies of the current element.

or

* a[i] is higher than the last seen value: in this case, a new tower has been found then we have to clear occurrencies count and increase the number of towers discovered.

At the end of each iteration, we check if the current tower is the highest by comparing the current number of occurrencies with the maximun number of occurrencies found.

## Complexity

The algorithm scan the vector only one time and the operations of each iterations are O(1) time.
No other data structures are involved.

So, the algoritm is O(n) time and O(1) space.