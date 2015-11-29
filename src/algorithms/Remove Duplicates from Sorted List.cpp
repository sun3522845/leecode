/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
              if(!head)
		  return head;
	   ListNode * node1 = head;
	   ListNode * node2 = head->next;
	   while(node2)
	   {
		   if(node1->val==node2->val)
		   {
			   node1->next=node2->next;
			   delete node2;
			   node2=node1->next;
		   }
		   else
		   {
			   node1=node1->next;
			   node2=node2->next;
		   }
		  


	   }
	   return head;
    }
};