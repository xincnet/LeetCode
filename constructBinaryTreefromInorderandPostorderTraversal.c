/*
   NO.106
   Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 */
#include "linkStack.h"
#include <stdlib.h>
#include <stdio.h>
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) 
{
	if (!inorder || !postorder || postorderSize != inorderSize || 0 == inorderSize) return NULL;

	PtrToStackNode postStack = creatStack();
	int indexPost = inorderSize - 1;
	int indexIn	 = inorderSize - 1;
	int isRight = 1;

	struct TreeNode* root = calloc(1, sizeof(struct TreeNode));
	root->val = postorder[indexPost];
	indexPost--;
	struct TreeNode* mark = root;
	push(root, postStack);

	while(indexPost >= 0)
	{
		if (!isEmpty(postStack) && top(postStack)->val == inorder[indexIn])
		{
			mark = top(postStack);
			pop(postStack);
			isRight = 0;
			indexIn--;
		}
		else
		{
			if (isRight)
			{
				mark->right = calloc(1, sizeof(struct TreeNode));
				mark->right->val = postorder[indexPost];
				mark = mark->right;
				push(mark, postStack);
				indexPost--;
			}
			else
			{
				isRight = 1;
				mark->left = calloc(1, sizeof(struct TreeNode));
				mark->left->val = postorder[indexPost];
				mark = mark->left;
				push(mark, postStack);
				indexPost--;
			}
		}
	}
	return root;
}
int main()
{
	struct TreeNode* a = calloc(1, sizeof(struct TreeNode));
	if (!a->left) printf("OK\n");
}
