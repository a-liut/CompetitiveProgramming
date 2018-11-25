# Check for BST

## Solution

To check that a binary tree is a BST, checking only direct children of a node is not sufficient.
By definition, for a generic node n, is necessary to check that the value of n is greater than the value of each nodes in the left subtree and lower than the value of each node in the right subtree. So, it suffices to check that the maximum value in the left subtree is less that the value of n and the minimum value in the right subtree is greater that the value of n.

The recursive algorithm is a variant of DFS traversal which returns a boolean that indicates if the current node is the root of a BST and provides to the current node the possibility to notify the parent the maximum value of its left subtree and the minimum value of its right subtree.
We distinguish three possible cases for a node:
* If the node is empty then its (empty) tree is a BST, so the maximum value and the minimum values are respectively INT_MIN and INT_MAX (those are indeed the bottom and the top value).
* If a node is a leaf the its tree is a BST, since it has no children to check. In this case, minimum and maximum values are the value of the current node.
* In all other cases the algorithm analyze the left subtree of the current node. If the left node is a valid BST, it check also the right subtree. If any of the two is not a valid BST, then false is returned to the parent, without performing any other check. In case both of the subtrees are BST, the algorithm verify the BST property on the current node, returning the corresponding result to the parent. 

## Complexity

The algorithm is basically a DFS, evaluating a node only once and performing O(1) operations for each node. 
Given a binary tree T=(N, E), the algorithm time complexity is O(n + e) where n = |N| and e = |E|.
As we are using binary trees, e = 2n, so the algorithm time complexity is O(n + 2n) = O(n) with O(1) additional space.
