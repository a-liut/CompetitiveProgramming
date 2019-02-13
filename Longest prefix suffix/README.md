# Longest prefix suffix

## Solution

The solution can be found constructing the $\Pi$ (failure function) array used in the KMP algorithm.
Each of the array position $i$ contains the length of the prefix which is also a prefix ending at position $i$. Thus, the answer is the last element of this array.

## Complexity

The running time of this algorithm is $O(n)$ using $\Theta(n)$ additional space.