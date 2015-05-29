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
struct TreeLink
{
	struct TreeNode* curr;
	struct TreeLink* next;
	int depth;
};
int maxDepth(struct TreeNode* root) 
{
	int dep = -1;
	struct TreeLink* top = malloc(sizeof(struct TreeLink));
	top->curr = root;
	top->next = NULL;
	top->depth = 0;
	struct TreeLink* tail;
	tail = top;

	if (!root) return 0;
	while(top)
	{
		if (!top->curr->left && !top->curr->right)
		{
			if (top->depth > dep) dep = top->depth;
			struct TreeLink* tmp = top;
			top = top->next;
			free(top);
		}
		else
		{
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
	}
	return dep;
}
int main()
{
	struct TreeNode a;
	struct TreeNode a_left;
	struct TreeNode a_right;
	
	a.left = &a_left;
	a.right = &a_right;
	a.val = 1;

	a_left.left = NULL;
	a_left.right = NULL;
	a_left.val = 2;

	a_right.left = NULL;
	a_right.right = NULL;
	a_right.val = 3;

	printf("%d\n", maxDepth(&a));
}
