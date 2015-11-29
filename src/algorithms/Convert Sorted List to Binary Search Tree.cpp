/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getLenOfList(ListNode * head)
	{
		int len=0;
		while(head)
		{
			++len;
			head=head->next;
		}
		return len;
	}

	

  TreeNode* sortedListToBST(ListNode* head)
  {
        int len = getLenOfList(head);
		if(len==0)
		{
			return NULL;
		}
		else if(len==1)
		{
			TreeNode * node = new TreeNode(head->val);
			return node;
		}
		else
		{
			ListNode * p = head;
			for(int i=0;i<(len/2-1);i++)
			{
				p=p->next;
			}
			ListNode * tmp = p->next;
			p->next=NULL;
			TreeNode *left = sortedListToBST(head);
			TreeNode * root = new TreeNode(tmp->val);
			p=tmp->next;
			TreeNode * right = sortedListToBST(p);
			root->left = left;
			root->right = right;
			return root;
			
		}
  }
};