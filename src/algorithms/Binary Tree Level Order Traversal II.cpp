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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        deque<pair<int ,TreeNode * > > nodeQueue;
		nodeQueue.push_back(make_pair(0,root));
		while(!nodeQueue.empty())
		{
			pair<int,TreeNode *>  tmppair = nodeQueue.front();
			nodeQueue.pop_front();
			if(tmppair.second)
			{
				if(result.size()<tmppair.first+1)
				{
					vector<int> tmpvec;
					result.insert(result.begin(),tmpvec);
				}
				result[0].push_back(tmppair.second->val);
				nodeQueue.push_back(make_pair(tmppair.first+1,tmppair.second->left));
				nodeQueue.push_back(make_pair(tmppair.first+1,tmppair.second->right));
			}
		}
		return result;
    }
};