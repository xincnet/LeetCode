/*
   NO.114
   Given a binary tree, flatten it to a linked list in-place.

   For example,
   Given

   1
   / \
   2   5
   / \   \
   3   4   6
   The flattened tree should look like:
   1
   \
   2
   \
   3
   \
   4
   \
   5
   \
   6
   click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 */
#include <stdlib.h>
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode* flattenWithTail(struct TreeNode* root)
{
	if (!root) return NULL;
	struct TreeNode* tailLeft = NULL;
	struct TreeNode* tailRight = NULL;
	if (root->right)
		tailRight = flattenWithTail(root->right);
	if (root->left)
	{
		tailLeft = flattenWithTail(root->left);
		tailLeft->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}
	if (tailRight) return tailRight;
	else if (tailLeft) return tailLeft;
	else return root;
}
void flatten(struct TreeNode* root) 
{
	flattenWithTail(root);
}
