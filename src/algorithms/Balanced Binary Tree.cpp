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
    bool Height(TreeNode *root,int &height)
	{
		if(!root)
		{
			height=0;
			return true;
		}
		else
		{
			int leftheight=0;
			int rightheight=0;
			if(Height(root->left,leftheight)&&Height(root->right,rightheight))
			{
				if(leftheight==(rightheight+1) || rightheight==(leftheight+1) ||leftheight==rightheight)
				{
					leftheight<=rightheight? (height=rightheight):(height=leftheight);
					++height;
					return true;
				}
				else
				{
				    return false;
				}
			}
			else
			{
				return false;
			}
		
		}

	}

    bool isBalanced(TreeNode *root) 
	{
		int height;
        return Height(root,height);

    }
};