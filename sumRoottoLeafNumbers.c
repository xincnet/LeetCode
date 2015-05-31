/*
   NO.129
   Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

   An example is the root-to-leaf path 1->2->3 which represents the number 123.

   Find the total sum of all root-to-leaf numbers.

   For example,

   1
   / \
   2   3
   The root-to-leaf path 1->2 represents the number 12.
   The root-to-leaf path 1->3 represents the number 13.

   Return the sum = 12 + 13 = 25.
 */

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumNumbers(struct TreeNode* root) 
{
	int sum = 0;
	if (!root) return 0;
	if (!root->left && !root->right)
		return root->val;
	if (root->left)
	{
		root->left->val += root->val * 10;
		sum += sumNumbers(root->left);
	}
	if (root->right)
	{
		root->right->val += root->val * 10;
		sum += sumNumbers(root->right);
	}
	return sum;
}
