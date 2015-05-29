/*
   NO.104
   Given a binary tree, find its maximum depth.

   The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
#include <stdlib.h>
#define max(a, b) (a > b ? a : b)

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) 
{

	if (!root) return 0;
	else
	{
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		return 1 + max(L, R);
	}
}
