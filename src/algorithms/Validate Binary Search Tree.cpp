/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

 
    
   	bool isValidBST(TreeNode *root)
	{
		if(!root)
			return true;
		TreeNode * leftmax = root->left;
		if(leftmax)
		{
			while(leftmax->right)
			{
				leftmax=leftmax->right;
			}
			if(leftmax->val>=root->val)
			return false;
		}
		TreeNode * rightmin = root->right;
		if(rightmin)
		{
			while(rightmin->left)
			{
				rightmin=rightmin->left;
			}
			if(rightmin->val<=root->val)
			return false;
		}
		if(isValidBST(root->left)&&isValidBST(root->right))
		{
			return true;
		}
		return false;
    }
};