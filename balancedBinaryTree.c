/*
   NO.110
   Given a binary tree, determine if it is height-balanced.

   For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a > b ? a : b)
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int getDepth(struct TreeNode* root)
{
	if(!root) return 0;
	else
	{
		int L = getDepth(root->left);
		int R = getDepth(root->right);
		return 1 + max(L, R);
	}
}
bool isBalanced(struct TreeNode* root) 
{
	if (!root) return true;
	else
	{
		if (isBalanced(root->left) && isBalanced(root->right))
		{
			int L = getDepth(root->left);
			int R = getDepth(root->right);
			printf("L:%d	R:%d\n", L ,R);
			if (abs(L - R) <= 1) return true;
			else return false;
		}
		else return false;
	}
}
int main()
{
	struct TreeNode* a = malloc(sizeof(struct TreeNode));
	struct TreeNode* b1 = malloc(sizeof(struct TreeNode));
	struct TreeNode* b2 = malloc(sizeof(struct TreeNode));
//	struct TreeNode* c1 = malloc(sizeof(struct TreeNode));
//	struct TreeNode* c2 = malloc(sizeof(struct TreeNode));
	a->val = 1;
	b1->val = 2;
	b2->val = 3;
//	c1->val = 15;
//	c2->val = 7;
	a->left = NULL;
	a->right = b1;
	b1->left = NULL;
	b1->right = b2;
	b2->left = NULL;
	b2->right = NULL;
//	c1->left = c1->right = c2->left = c2->right = NULL;
	isBalanced(a);
}
