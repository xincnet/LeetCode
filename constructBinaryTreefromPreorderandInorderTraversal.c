/*
   NO.105
   Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 */
#include <stdlib.h>
#include <stdbool.h>
#include "linkStack.h"
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) 
{
	if (!preorder || !inorder || preorderSize != inorderSize || inorderSize) return NULL;
	
	PtrToStackNode preStack = creatStack();
	int indexPre = 0;
	int indexIn	 = 0;
	int isRight = 0;
	
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = preorder[indexPre];
	root->left = NULL;
	root->right = NULL;
	indexPre++;
	struct TreeNode* mark = root;
	push(root, preStack);

	
	while (indexPre < preorderSize)
	{
		if (!isEmpty(preStack) && top(preStack)->val == inorder[indexIn])
		{
			mark = top(preStack);
			pop(preStack);
			isRight = 1;
			indexIn++;
		}
		else
		{
			if(!isRight)
			{
				mark->left = malloc(sizeof(struct TreeNode));
				mark->left->val = preorder[indexPre];
				mark->left->left = NULL;
				mark->left->right = NULL;
				mark = mark->left;
				push(mark, preStack);
				indexPre++;
			}
			else
			{
				isRight = 0;
				mark->right = malloc(sizeof(struct TreeNode));
				mark->right->val = preorder[indexPre];
				mark->right->left = NULL;
				mark->right->right = NULL;
				mark = mark->right;
				push(mark, preStack);
				indexPre++;
			}
		}
	}
	return root;
}
int main()
{
}
