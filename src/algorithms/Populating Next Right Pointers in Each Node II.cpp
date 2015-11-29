/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
         deque<pair<TreeLinkNode *,int> >  treeque;
		if(!root)
			return;
		treeque.push_back(make_pair(root,0));
		while(!treeque.empty())
		{
			pair<TreeLinkNode *,int>  tmppair = treeque.front();
			treeque.pop_front();
			if(treeque.empty()||treeque.front().second>tmppair.second)
			{
				tmppair.first->next=NULL;
			}
			else
			{
				tmppair.first->next=treeque.front().first;
			}
			if(tmppair.first->left)
				treeque.push_back(make_pair(tmppair.first->left,tmppair.second+1));
			if(tmppair.first->right)
				treeque.push_back(make_pair(tmppair.first->right,tmppair.second+1));
		}
    }
};