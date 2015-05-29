/*
   NO.100
   Given two binary trees, write a function to check if they are equal or not.

   Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */
#include <stdbool.h>
#include <stdlib.h>
struct TreeNode 
{
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
};

bool isEqual(struct TreeNode* left, struct TreeNode* right)
{
	if (NULL == left && NULL == right) return true;
	else if(NULL != left && NULL != right)
	{
		if (left->val != right->val) return false;
		if (isEqual(left->left, right->left) && isEqual(left->right, right->right))
			return true;
		else return false;
	}
	else return false;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
	return isEqual(p,q);
}
