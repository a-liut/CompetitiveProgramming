# Queue

## Solution

The algorithm sorts the persons by their $a_i$ value. With ordered people, it can check whether a solution exists by verifying the property $\forall i. a_i <= i$. If it is not the case, it means that there is no viable solution because the algorithm can't find a proper ordering of persons satisfying the given constraints.

To get the solution, the algorithm assigns a height to each person. Using the ordered list of people, it puts the person $i$ in position $a_i + k$ where $k$ is the number of values lower or equal than $a_i$ in $[a_{i+1}-a_n]$. k can be computed using a fenwick tree built by scanning the array from right to left counting the occurrences of equal values of $a_i$.

The value k is needed because in position $a_i$ there can be placed another person whose $a$ value is equal to the current person's $a$ value, thus we need to skip of some positions.

## Complexity

The time complexity of the algorithm is dominated by the sorting operation and the fenwick tree rangeSum operation.

It requires:

- $O(nlogn)$ to sort the people by $a_i$, build the fenwick tree and compute k using rangeSum
- $O(n)$ to assign heights and print the solution

Thus, the overall time complexity is $O(nlogn)$ using $O(n)$ additional space to store the fenwick tree.