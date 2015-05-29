/*
   NO.112
   Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

   For example:
   Given the below binary tree and sum = 22,
   5
   / \
   4   8
   /   / \
   11  13  4
   /  \      \
   7    2      1
   return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) 
{
	if (NULL == root)return false;
	if (NULL == root->left && NULL == root->right && sum == root->val)return true;
	if (NULL != root->left)
	{
		root->left->val += root->val;
		if (hasPathSum(root->left, sum)) return true;
	}
	if (NULL != root->right)
	{
		root->right->val += root->val;
		if (hasPathSum(root->right, sum)) return true;
	}
	return false;
}
