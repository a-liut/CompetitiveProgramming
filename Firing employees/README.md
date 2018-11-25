# Firing employees

## Solution

The employees can be organized as a tree and each node value is the rank of the corresponding employee. Thus, deciding whether an employee is blacklisted or not is a simple variant of DFS in which we maintain the number of previous nodes traversed and then check the blacklisting property.

We use an implicit representation of the tree, storing seniors in a vector.
To know if an employee is blacklisted, we need the number of its seniors. We can compute them as follows: 

For an employee i, let p be its parent, then:
* rank(i) = 0: i is Mr. Alfred and he has 0 seniors
* rank(i) > 0: the number of seniors of i is computed as 1 plus the number of the seniors of its parent p. If seniors of p aren't already computed, we compute them recursively, climbing up the tree. In this way, the number of senior of an employee is calculated only once and reused for the next iterations.

When all counters are computed, we just scan them checking whether the respective employee is blacklisted.

## Complexity

The algorithm is divided in two parts:

* Compute seniors of each employee: Each employee is processed at most once since the count_parents function consider only employees for whom is not already computed the number of seniors and it is applied only once to all employees. Thus, the time complexity is theta(n).
* Compute the number of blacklisted employees: Each employee is considered only once, so this operation takes theta(n).

So, the overall complexity is theta(n + n) = theta(n) time using O(n) additional space to store the number of each employee seniors.
