/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        
		TreeNode * node = root;
		while(node)
		{
			TreeNode * tmp = node;
			miniTree.push(tmp);
			node = node->left;
		}

    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		bool ret=miniTree.empty();
		return !ret;
    }

    /** @return the next smallest number */
    int next() {
		TreeNode * node = miniTree.top();
		int value = node->val;
		 miniTree.pop();
		 node = node->right;
		 while(node)
		{
			TreeNode * tmp = node;
			miniTree.push(tmp);
			node = node->left;
		}
		 return value;
    }

private :
	stack<TreeNode *> miniTree;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */