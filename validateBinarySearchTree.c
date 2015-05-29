/*
   NO.98
   Given a binary tree, determine if it is a valid binary search tree (BST).

   Assume a BST is defined as follows:

   The left subtree of a node contains only nodes with keys less than the node's key.
   The right subtree of a node contains only nodes with keys greater than the node's key.
   Both the left and right subtrees must also be binary search trees.
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
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int findMax(struct TreeNode* root)
{
//	if (!root) return NULL;
	while(root->right) root = root->right;
	return root->val;
}
int findMin(struct TreeNode* root)
{
//	if (!root) return NULL;
	while(root->left) root = root->left;
	return root->val;
}
bool isValidBST(struct TreeNode* root) 
{
	if (!root) return true;
	if (root->left)
	{
		if (findMax(root->left) >= root->val) return false;
		if (!isValidBST(root->left)) return false;
	}
	if (root->right)
	{
		if (findMin(root->right) <= root->val) return false;
		if (!isValidBST(root->right)) return false;
	}
	return true;
}
int main()
{
	struct TreeNode* a = malloc(sizeof(struct TreeNode));
	struct TreeNode* b1 = malloc(sizeof(struct TreeNode));
	a->val = 1;
	b1->val = 1;
	a->left = b1;
	a->right = NULL;
	b1->left = NULL;
	b1->right = NULL;
	printf("%d\n", isValidBST(a));
}
