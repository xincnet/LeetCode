/*
   NO.111
   Given a binary tree, find its minimum depth.

   The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */
 /*
 	BFS
 */
#include <stdio.h>
#include <stdlib.h>

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

int minDepth(struct TreeNode* root) 
{
	int dep = -1;
	struct TreeLink* top = malloc(sizeof(struct TreeLink));
	top->curr = root;
	top->next = NULL;
	top->depth = 0;
	struct TreeLink* tail;
	tail = top;
	
	if (NULL == root) return 0;
	while(dep < 0)
	{
		if (!top->curr->left && !top->curr->right) dep = top->depth;
		if (top->curr->left)
		{
			struct TreeLink* tmp = malloc(sizeof(struct TreeLink));
			tmp->curr = top->curr->left;
			tmp->next = NULL;
			tmp->depth = top->depth + 1;
			tail->next = tmp;
			tail = tmp;
		}
		if (top->curr->right)
		{
			struct TreeLink* tmp = malloc(sizeof(struct TreeLink));
			tmp->curr = top->curr->right;
			tmp->next = NULL;
			tmp->depth = top->depth + 1;
			tail->next = tmp;
			tail = tmp;
		}
		if (top->curr->left || top->curr->right)
		{
			struct TreeLink* tmp = top;
			top = top->next;
			free(tmp);
		}
	}
	while(top)
	{
		struct TreeLink* tmp = top;
		top = top->next;
		free(tmp);
	}
	return dep + 1;
}
