/*
   NO.103
   Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

   For example:
   Given binary tree {3,9,20,#,#,15,7},
   3
   / \
   9  20
   /  \
   15   7
   return its zigzag level order traversal as:
   [
   [3],
   [20,9],
   [15,7]
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
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) 
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
			reArray[curDepth - 1] = malloc(sizeof(int) * depNumCou);
			if (curDepth % 2)
				for (int i = 0; i < depNumCou; i++)
					reArray[curDepth - 1][i] = store[i];
			else
				for (int i = 0; i < depNumCou; i++)
					reArray[curDepth - 1][i] = store[depNumCou - 1 - i];
			col[curDepth - 1] = depNumCou;
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
	reArray[curDepth - 1] = malloc(sizeof(int) * depNumCou);
	if (curDepth % 2)
		for (int i = 0; i < depNumCou; i++)
			reArray[curDepth - 1][i] = store[i];
	else
		for (int i = 0; i < depNumCou; i++)
			reArray[curDepth - 1][i] = store[depNumCou - 1 - i];
	col[curDepth - 1] = depNumCou;
	free(store);

	*columnSizes = col;

	return reArray;
}

