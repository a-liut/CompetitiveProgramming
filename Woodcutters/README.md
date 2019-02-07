# Woodcutters

## Solution

The answer can be found using the following greedy algorithm. The algorithm process the trees from left to right, ordered by their position. For each tree, check if it is possible to cut it down to the left or to the right. If the tree fell down to the left, that choice doesn't affect processing of the next tree. If the tree fell down to the right, it may be the case that it prevents the next tree to fall to the left. But if the algorithm chose to cut down the next tree, that tree will be cut down to the left it applies the same reasoning as before. So, in the end, let a tree fall to the right may provoke only a swap of trees to fall that does not make the answer wrong.

## Complexity

This greedy algorithm processes a tree only once, and all the operations performed per tree take constant time. Thus, the time complexity of this algorithm is $\Theta(n)$.