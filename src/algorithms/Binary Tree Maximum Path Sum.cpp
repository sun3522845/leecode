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
      int max;  
    int maxPath(TreeNode *root) {  
        if (root == NULL) {  
            return 0;  
        }     
        else {  
            int a = maxPath(root->left);  
            int b = maxPath(root->right);  
            int value = root->val;  
            value += a > 0 ? a : 0;  
            value += b > 0 ? b : 0;  
            if (value > max) {  
                max = value;  
            }  
            if (a > b && a > 0) {  
                return root->val + a;  
            }  
            if (b > a && b > 0) {  
                return root->val + b;  
            }  
            return root->val;  
        }  
    }  
      
public:  
    int maxPathSum(TreeNode *root) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        max = -10000000;  
        maxPath(root);  
        return max;  
    }
    
};