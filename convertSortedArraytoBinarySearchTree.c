/*
   NO.108
   Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */
#include <stdlib.h>
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
	if (0 >= numsSize) return NULL;
	
	struct TreeNode* root = NULL;
	if (1 == numsSize)
	{
		root = malloc(sizeof(struct TreeNode));
		root->val = nums[0];
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	if (2 == numsSize)
	{	
		root = malloc(sizeof(struct TreeNode));
		root->val = nums[0];
		root->left = NULL;
		struct TreeNode* ri = malloc(sizeof(struct TreeNode));
		ri->val = nums[1];
		ri->left = NULL;
		ri->right = NULL;
		root->right = ri;
		return root;
	}
	if (numsSize % 2)
	{
		root = malloc(sizeof(struct TreeNode));
		root->val = nums[numsSize / 2];
		root->left = sortedArrayToBST(nums, numsSize / 2);
		root->right = sortedArrayToBST(&nums[(numsSize / 2) + 1], numsSize / 2);
		return root;
	}
	if (!(numsSize % 2))
	{
		root = malloc(sizeof(struct TreeNode));
		root->val = nums[(numsSize / 2) - 1];
		root->left = sortedArrayToBST(nums, (numsSize / 2) - 1);
		root->right = sortedArrayToBST(&nums[numsSize / 2], numsSize / 2);
		return root;
	}
}
