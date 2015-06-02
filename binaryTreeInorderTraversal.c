/*
   NO.94
   Given a binary tree, return the inorder traversal of its nodes' values.

   For example:
   Given binary tree {1,#,2,3},
   1
   \
   2
   /
   3
   return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
1
/ \
2   3
/
4
\
5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
int* inorderTraversal(struct TreeNode* root, int* returnSize) 
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
			if (st->right)
			{
				pop(nodeStack);
				push(st->right, nodeStack);
				push(st, nodeStack);
				isSpread[stackCount - 1] = true;
				stackCount++;
				index++;
			}
			if (st->left)
			{
				push(st->left, nodeStack);
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
		re[i] = array[i];
	*returnSize = numCount;
	return re;
}
int main()
{
	struct TreeNode* a1 = calloc(1, sizeof(struct TreeNode));
	struct TreeNode* b1 = calloc(1, sizeof(struct TreeNode));
	a1->val = 1;
	b1->val = 2;
	a1->right = b1;
	
	int size = 0;
	inorderTraversal(a1, size);
	return 0;
}
