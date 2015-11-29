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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        
        if(p&&q&&p->val==q->val)
        {
            if(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))
            return true;
        }
        else if(!p&&!q)
        {
            return true;
            
        }
        else
        {
            return false;
            
        }
        
    }
};