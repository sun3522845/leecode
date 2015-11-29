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
    int maxDepth(TreeNode *root) {
        
        if(!root)
            return 0;
        int max=1;
        int leftmax= maxDepth(root->left);
        int rightmax=maxDepth(root->right);
        leftmax>rightmax?(max+=leftmax):(max+=rightmax);
        return max;
    }
};