# Maximum Path Sum

The algorithm perform a post-order traversal of the tree.
For each node, it computes the path with maximum sum from a leaf to the current node for both of the subtrees.

There are three possible cases for a node:

- The node is empty: there is no path

- The node is a leaf: the only possible path available is the path from the node to itself, so the value of the node is returned

- The node is an internal one:

	*  The node has only one subtree: the path is composed by the current node and the maximum path for the subtree
	*  the node has both subtrees: the path with maximum value is the maximum of the two subtrees plus the current node. In this case, the algorithm has to check if the maximum result path found is still the maximum w.r.t. the new candidate path made by the current node and both of the subtrees. If it is not the case, then the maximum is updated.

# Complexity

The algorithm visit each note at most one time and the operations made to compute the maximum path are O(1).
Hence, the algorithm takes O(n) time where n is the number of nodes and uses no additional space.