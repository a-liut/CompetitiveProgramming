/*
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
int _findMaxPath(struct Node *node, int &max)
{
	// Empty tree
	if(node == NULL) return NULL;
	int maxLeft = _findMaxPath(node->left, max);
	int maxRight = _findMaxPath(node->right, max);

	// The node is a leaf
	if(maxLeft == NULL && maxRight == NULL) return node->data;

	// Take the maximum path passing through node
	int currentMax = node->data;
	currentMax = currentMax + (maxLeft > maxRight ? maxLeft : maxRight);

	// Both subtrees exists
	if(maxLeft != NULL && maxRight != NULL) {
		// Join the maximum path from the left and from the right using node
		int current = node->data + maxLeft + maxRight;
		// Update the maximum if needed
		if(max < current) {
			max = current;
		}
	}

	return currentMax;
}

int maxPathSum(struct Node *root)
{
    int max = INT_MIN;
	_findMaxPath(root, max);
	return max;
}