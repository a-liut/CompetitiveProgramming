# Towers

## Solution

Given a multiset S containing only natural numbers, finding the height of the largest tower and the number of towers correspond respectively to find the number wich appers more times in S and the number of distinct values in S.

The algorithm perform two steps: the former sorts the vector in descending order. In this way, vector's elements are contiguous and this make the counting of the occurrencies much simpler.
The latter is counting the occurrencies: We have two possible cases for a generic element i:

* a[i] is equals to the last seen value: in this case, just increase the number of occurencies of the current element.

or

* a[i] is higher than the last seen value: in this case, a new tower has been found then we have to clear occurrencies count and increase the number of towers discovered.

At the end of each iteration, we check if the current tower is the highest by comparing the current tower height with the maximun found.

## Complexity

Sorting the vector requires theta(nlog(n)) comparisons and the algorithm scan the vector only one time performing operations of constant time.
No other data structures are involved.

So, the algoritm is theta(nlog(n)) time and theta(1) space.