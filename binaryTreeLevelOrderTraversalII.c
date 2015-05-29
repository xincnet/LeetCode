/*
   NO.107
   Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

   For example:
   Given binary tree {3,9,20,#,#,15,7},
   3
   / \
   9  20
   /  \
   15   7
   return its bottom-up level order traversal as:
   [
   [15,7],
   [9,20],
   [3]
   ]
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


struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define max(a, b) (a > b ? a : b)

struct TreeLink
{
	struct TreeNode* curr;
	struct TreeLink* next;
	int depth;
};

int maxDepth(struct TreeNode* root) 
{
	if (!root) 
	{
		return 0;
	}
	else
	{
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		return 1 + max(L, R);
	}
	return -1;
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
	if (!root) return NULL;
	int depth = maxDepth(root);
	*returnSize = depth;
	int* col = malloc(sizeof(int) * depth);
	int** reArray = malloc(sizeof(int*) * depth);
	int curDepth = 1;
	struct TreeLink* top = malloc(sizeof(struct TreeLink));
	top->curr = root;
	top->next = NULL;
	top->depth = 1;
	struct TreeLink* tail = top;
	int depNumCou = 0;
	int* store = malloc(sizeof(int) * pow(2, (depth - 1)));
	while(top)
	{
		if (top->depth > curDepth)
		{
			reArray[depth - curDepth] = malloc(sizeof(int) * depNumCou);
			for (int i = 0; i < depNumCou; i++)
			{
				reArray[depth - curDepth][i] = store[i];
			}
			col[depth - curDepth] = depNumCou;
			curDepth++;
			depNumCou = 0;
			store[depNumCou] = top->curr->val;
			depNumCou++;
		}
		else
		{
			store[depNumCou] = top->curr->val;
			depNumCou++;
		}
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
		struct TreeLink* tmp = top;
		top = top->next;
		free(tmp);
	}
	reArray[depth - curDepth] = malloc(sizeof(int) * depNumCou);
	for (int i = 0; i < depNumCou; i++)
	{
		reArray[depth - curDepth][i] = store[i];
	}
	col[depth - curDepth] = depNumCou;
	free(store);

	*columnSizes = col;

	return reArray;
}

