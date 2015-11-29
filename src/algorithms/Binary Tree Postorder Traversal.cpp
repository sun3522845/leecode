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
    vector<int> postorderTraversal(TreeNode *root) {
          vector<int> result;
		 if(!root)
			 return result;
		 vector<int> left = postorderTraversal(root->left);
		  vector<int> right=postorderTraversal(root->right);
		  
		  for(vector<int>::iterator it =left.begin();it!=left.end();it++)
		  {
			  result.push_back(*it);
		  }
		 
		  for(vector<int>::iterator it =right.begin();it!=right.end();it++)
		  {
			  result.push_back(*it);
		  }
		   result.push_back(root->val);
		  return result;
    }
};