# Little Girl and Maximum Sum

## Solution

The little girl needs to find a permutation of the input values such that the queries return the maximum possible sum. This can be done by placing the highest values into locations that are involved the most by the queries.

In order to find the solution we need to perform several steps:

1. Compute the frequencies for each location of the array
2. Sort array positions by frequency
3. Sort values of the array
4. Assign in decreasing order values to locations
5. Compute the sum of the range sum queries

In order to make the range sum queries efficient, the algorithm uses a BIT wich guarantee O(log(n)) for add and rangeSum operations.

Assigning the highest values to the most involved locations guarantees that the value is considered the maximum number of queries possible, thus the overall sum is for sure the maximum possible.

## Complexity

The complexity for each operation is:

1. Build the frequency array: theta(q). We perform a linear scan of all queries.
2. Sort position by frequency: O(nlog(n)): The algorithm stores into a priority_queue elements sorting by frequency. Each add operation takes O(log(n)).
3. Sort values of the array: O(nlog(n))
4. Assign in decreasing order values to locations: theta(nlog(n)): the algorithm extract one by one each element from the queue and adds it to the BIT.
5. Compute the range sum queries: O(qlog(n)). Each range sum query takes O(log(n)) and we need to consider q queries.

The overall complexity is O(q + nlog(n) + qlog(n)) time using O(n) additional space for storing the BIT and the frequency array;