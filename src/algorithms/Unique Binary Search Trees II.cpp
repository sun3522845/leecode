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
   vector<TreeNode *> generateTree(int beg,int end)
    {

        vector<TreeNode *> result;
        if(beg>end)
		{
			result.push_back(NULL);
		}
		for(int i=beg;i<=end;i++)
        {
            vector<TreeNode *> lefttree = generateTree(beg,i-1);
            vector<TreeNode *> righttree = generateTree(i+1,end);
            for( vector<TreeNode *>::iterator it=lefttree.begin();it!=lefttree.end();it++)
            {
                 for( vector<TreeNode *>::iterator lt=righttree.begin();lt!=righttree.end();lt++)
                 {
                     TreeNode * tmproot = new TreeNode(i);
					 tmproot->left = *it;
					 tmproot->right = *lt;
					 result.push_back(tmproot);
                 }
            }
            
        } 
        
        return result;
        
    }
    
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        if(n==0)
        {
           result.push_back(NULL);
           return result;
        }
        
        for(int i=1;i<=n;i++)
        {
            vector<TreeNode *> lefttree = generateTree(1,i-1);
            vector<TreeNode *> righttree = generateTree(i+1,n);
			 for( vector<TreeNode *>::iterator it=lefttree.begin();it!=lefttree.end();it++)
            {
                 for( vector<TreeNode *>::iterator lt=righttree.begin();lt!=righttree.end();lt++)
                 {
                     TreeNode * tmproot = new TreeNode(i);
					 tmproot->left = *it;
					 tmproot->right = *lt;
					 result.push_back(tmproot);
                 }
            }
        }
		return result;
    }
};