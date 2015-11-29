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

   
    
    bool hasPathSum(TreeNode *root, int sum) {
        
        if(root)
        {
            if(root->val==sum&&!root->left&&!root->right)
            {
                return true;
            }
            else
            {
                if(root->left&&hasPathSum(root->left, sum-root->val))
                {
                    return true;
                }
                else if(root->right&&hasPathSum(root->right, sum-root->val))
                {
                    return true;
                    
                }
                return false;
            }
            
            
        }
    
        return false;
    }
};