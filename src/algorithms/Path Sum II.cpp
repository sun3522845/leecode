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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
       	vector<vector<int> > result;
    
	if(root)
    {
        if(root->val==sum&&!root->left&&!root->right)
        {
			vector<int> tmp;
			tmp.push_back(root->val);
			result.push_back(tmp);
            return result;
        }
        else
        {
            if(root->left)
            {
				vector<vector<int> > leftresult;
				leftresult=pathSum(root->left, sum-root->val);
				if(!leftresult.empty())
				{
					for(vector<vector<int> >::iterator it=leftresult.begin();it!=leftresult.end();it++)
					{
						it->insert(it->begin(),root->val);
						result.push_back(*it);
					}
				}
            }
            if(root->right)
            {
				vector<vector<int> > rightresult;
				rightresult=pathSum(root->right, sum-root->val);
				if(!rightresult.empty())
				{
					for(vector<vector<int> >::iterator it=rightresult.begin();it!=rightresult.end();it++)
					{
						it->insert(it->begin(),root->val);
						result.push_back(*it);
					}
				}
            }
           
        }
            
            
    }
    
    return result;
    }
};