/*
   Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

   For example, this binary tree is symmetric:

   1
   / \
   2   2
   / \ / \
   3  4 4  3
   But the following is not:
   1
   / \
   2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
#include <stdbool.h>
#include <stdio.h>
struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
};

bool judgeEqual(struct TreeNode* Left, struct TreeNode* Right)
{
		if (NULL == Left && NULL == Right)return true;
		else if(NULL != Left && NULL != Right)
		{
			if (Left->val != Right->val) return false;
			else 
			{
				if (judgeEqual(Left->left, Right->right) && judgeEqual(Left->right, Right->left))
					return true;
				else return false;
			}
		}
		else return false;
}
bool isSymmetric(struct TreeNode* root) 
{
	if (NULL == root) return true;
	return judgeEqual(root->left, root->right);
}
