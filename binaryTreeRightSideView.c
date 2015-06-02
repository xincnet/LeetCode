/*
   NO.199
   Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

   For example:
   Given the following binary tree,
   1            <---
   /   \
   2     3         <---
   \     \
   5     4       <---
   You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
 */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define max(a, b) (a > b ? a : b)

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeLink
{
	struct TreeNode* curr;
	struct TreeLink* next;
	int depth;
};

int maxDepth(struct TreeNode* root) 
{
	if (!root) 
		return 0;
	else
	{
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		return 1 + max(L, R);
	}
	return -1;
}
int* rightSideView(struct TreeNode* root, int* returnSize)
{
	if (!root) return NULL;

	int depth = maxDepth(root);
	*returnSize = depth;
	int* col = malloc(sizeof(int) * depth);

	int curDepth = 1;
	struct TreeLink* top = calloc(1, sizeof(struct TreeLink));
	top->curr = root;
	top->depth = 1;
	struct TreeLink* tail = top;
	int store;

	while(top)
	{
		if (top->depth > curDepth)
		{
			col[curDepth - 1] = store;
			curDepth++;
		}
		store = top->curr->val;
		if (top->curr->left)
		{
			tail->next = calloc(1, sizeof(struct TreeLink));
			tail->next->curr = top->curr->left;
			tail->next->depth = top->depth + 1;
			tail = tail->next;
		}
		if (top->curr->right)
		{
			tail->next = calloc(1, sizeof(struct TreeLink));
			tail->next->curr = top->curr->right;
			tail->next->depth = top->depth + 1;
			tail = tail->next;
		}
		struct TreeLink* tmp = top;
		top = top->next;
		free(tmp);
	}

	col[curDepth - 1] = store;
	return col;
}
int main()
{
}

