/*
   NO.144
   Given a binary tree, return the preorder traversal of its nodes' values.

   For example:
   Given binary tree {1,#,2,3},
   1
   \
   2
   /
   3
   return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
 */
#include "linkStack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int maxDepth(struct TreeNode* root) 
{
	if (!root) 
		return 0;
	else
	{
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		return 1 + (L > R ? L : R);
	}
	return -1;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
	if (!root) return NULL;
	int depth = maxDepth(root);
	bool* isSpread = calloc(pow(2, depth), sizeof(bool));
	int* array = calloc(pow(2, depth), sizeof(int));
	int numCount = 0;
	int stackCount = 0;

	PtrToStackNode nodeStack = creatStack();
	push(root, nodeStack);
	isSpread[stackCount] = true;
	stackCount++;

	while (top(nodeStack))
	{
		int index = stackCount - 1;
		struct TreeNode* st = top(nodeStack);
		if (isSpread[index])
		{
			if (st->left)
			{
				push(st->left, nodeStack);
				isSpread[stackCount] = true;
				stackCount++;
			}
			if (st->right)
			{
				push(st->right, nodeStack);
				isSpread[stackCount] = true;
				stackCount++;
			}
			isSpread[index] = false;
		}
		else
		{
			array[numCount] = st->val;
			numCount++;
			pop(nodeStack);
			stackCount--;
		}
	}
	int* re = calloc(numCount, sizeof(int));
	for (int i = 0; i < numCount; i++)
		re[i] = array[numCount - 1 - i];
	*returnSize = numCount;
	return re;

}
