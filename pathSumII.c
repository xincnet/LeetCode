/*
   NO.113
   Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

   For example:
   Given the below binary tree and sum = 22,
   5
   / \
   4   8
   /   / \
   11  13  4
   /  \    / \
   7    2  5   1
   return
   [
   [5,4,11,2],
   [5,8,4,5]
   ]
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define max(a, b) (a > b ? a : b)
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int maxDepth(struct TreeNode* root) 
{
	if (!root) return 0;
	else
	{
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		return 1 + max(L, R);
	}
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) 
{
	if (!root) return NULL;
	int depth = maxDepth(root);
	int** reArray = malloc(sizeof(int*) * pow(2, depth));
	int* count = malloc(sizeof(int) * pow(2, depth));
	int stackNum = 0;

	if (root->left)
	{
		int** reTmp;
		int* colTmp;
		int sizeTmp;

		reTmp = pathSum(root->left, (sum - root->val), &colTmp, &sizeTmp);
		for (int i = 0; i < sizeTmp; i++)
		{
			reArray[stackNum + i] = malloc(sizeof(int*) * (colTmp[i] + 1));
			count[stackNum + i] = colTmp[i] + 1;
			reArray[stackNum + i][0] = root->val;
			for (int j = 0; j < colTmp[i]; j++)
			{
				reArray[stackNum + i][j + 1] = reTmp[i][j];
			}
		}
		free(reTmp);
		free(colTmp);
		stackNum += sizeTmp;
	}
	if (root->right)
	{
		int** reTmp;
		int* colTmp;
		int sizeTmp;

		reTmp = pathSum(root->right, (sum - root->val), &colTmp, &sizeTmp);
		for (int i = 0; i < sizeTmp; i++)
		{
			reArray[stackNum + i] = malloc(sizeof(int*) * (colTmp[i] + 1));
			count[stackNum + i] = colTmp[i] + 1;
			reArray[stackNum + i][0] = root->val;
			for (int j = 0; j < colTmp[i]; j++)
			{
				reArray[stackNum + i][j + 1] = reTmp[i][j];
			}
		}
		free(reTmp);
		free(colTmp);
		stackNum += sizeTmp;
	}
	if (!root->left && !root->right)
	{
		if (root->val == sum)
		{
			reArray[0] = malloc(sizeof(int));
			reArray[0][0] = root->val;
			stackNum = 1;
			count[0] = 1;
		}
		else
		{
			reArray[0] = NULL;
			stackNum = 0;
			count[0] = 0;
		}
	}
	*returnSize = stackNum;
	*columnSizes = count;
	return reArray;
}

int main()
{
	struct TreeNode* a1 = malloc(sizeof(struct TreeNode));
	
	struct TreeNode* b1 = malloc(sizeof(struct TreeNode));
	struct TreeNode* b2 = malloc(sizeof(struct TreeNode));
	
	struct TreeNode* c1 = malloc(sizeof(struct TreeNode));
	struct TreeNode* c2 = malloc(sizeof(struct TreeNode));
	struct TreeNode* c3 = malloc(sizeof(struct TreeNode));
	
	struct TreeNode* d1 = malloc(sizeof(struct TreeNode));
	struct TreeNode* d2 = malloc(sizeof(struct TreeNode));
	struct TreeNode* d3 = malloc(sizeof(struct TreeNode));
	struct TreeNode* d4 = malloc(sizeof(struct TreeNode));
	
	a1->val = 5;
	a1->left = b1;
	a1->right = b2;
	
	b1->val = 4;
	b1->left = c1;
	b1->right = NULL;
	b2->val = 8;
	b2->left = c2;
	b2->right = c3;
	
	c1->val = 11;
	c1->left = d1;
	c1->right = d2;
	c2->val = 13;
	c2->left = NULL;
	c2->right = NULL;
	c3->val = 4;
	c3->left = d3;
	c3->right = d4;
	
	d1->val = 7;
	d1->left = NULL;
	d1->right = NULL;
	d2->val = 2;
	d2->left = NULL;
	d2->right = NULL;
	d3->val = 5;
	d3->left = NULL;
	d3->right = NULL;
	d4->val = 1;
	d4->left = NULL;
	d4->right = NULL;
	
	int* col;
	int size;
	int** re;
	re = pathSum(a1, 22, &col, &size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			printf("%d	", re[i][j]);
		}
		printf("\n");
	}
}
