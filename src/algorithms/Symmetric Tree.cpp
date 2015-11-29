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
    bool isEqual(TreeNode * left,TreeNode * right)
 {
	 if(left&&right&&left->val==right->val)
	 {
		 if(isEqual(left->left,right->right)&&isEqual(left->right,right->left))
			 return true;
	 }
	 else if(!left&&!right)
	 {
		return true;
	 }
	 else
	 {
		return false;
	 }
 }

    bool isSymmetric(TreeNode *root) {
        
		if(!root)
			return true;
		return  isEqual(root->left,root->right);
    }
};