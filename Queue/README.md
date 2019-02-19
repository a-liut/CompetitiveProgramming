# Queue

## Solution

The algorithm sorts the persons by their $a_i$ value. With ordered people, it can check whether a solution exists by verifying the property $\forall i. a_i <= i$. If it is not the case, it means that there is no viable solution because the algorithm can't find a proper ordering of persons satisfying the given constraints.

To get the solution, the algorithm assigns a height to each person by assigning the height to person at position $i - p[i].a$. The update operations on the vector ensure that there is always $p[i].a$ people taller than the guy at position $i$.

## Complexity

The time complexity of the algorithm is dominated by the sorting operation and the updates on the height vector.

It requires:

- $O(nlogn)$ to sort the people by $a_i$ and update the height vector
- $O(n)$ to assign heights and print the solution

Thus, the overall time complexity is $O(nlogn)$ using $O(n)$ additional space to store the fenwick tree.