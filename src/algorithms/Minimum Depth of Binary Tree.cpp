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
   
  
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        else if(!root->left&&!root->right)
            return 1;
        else
        {
            int leftmin= minDepth(root->left);
            int rightmin = minDepth(root->right);
            if(leftmin==0)
            {
                return rightmin+1;
            }
            else if(rightmin==0)
            {
                return leftmin+1;
            }
            else if(leftmin<rightmin)
            return leftmin+1;
             else
            return rightmin+1;
            
        }
       
    }
};