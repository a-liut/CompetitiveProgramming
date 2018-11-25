# Preorder Traversal and BST

## Solution

The preorder traversal impose on the linearized element a precise order. For each element, after printing the element value, smaller children are printed first, then the bigger ones. If in the sequence of the bigger nodes there are some element that are lower than the parent, then the tree is not a BST because the BST property is violated.

To check that the sequence is a valid BST preorder traversal linearization, the algorithm use a stack to maintain the traversed nodes.
First, the root of the tree is pushed into the stack, then it procedes as follows:

- if the current value is greater than the stack top, then it must be the right child of a node that is already traversed. So, lower elements are removed from the stack to climb up the tree, until the first node that can have the element as right child. Then the values is pushed into the stack, to consider a new subtree.
- if the current value is lower than the stack top, then two cases are possible:
    - if it is greater than the grand parent of the current root, then it must be the left child of the current stack top node. So, the current element is pushed into the stack to consider a new subtree.
    - otherwise, if it is lower than the grand parent of the current root, then the tree is not a BST as this node is on the right subtree of a node but it is lower than the value of the root. So, the algorithm will report false.

The algorithm ends when all nodes are checked respecting the BST property.

## Complexity

The algorithm does a linear scan of the input array and each item is pushed and popped from the stack at least once.
So, the algorithm takes O(n) time and use O(n) additional space i.e. the stack.