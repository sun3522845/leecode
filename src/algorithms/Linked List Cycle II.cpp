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
    ListNode *detectCycle(ListNode *head) {
           ListNode *p,*q;
		   p=q=head;
		   while(q&&q->next)
		   {
			   q=q->next->next;
			   p=p->next;
			   if(p==q)
				   break;
		   }
		   
		   if(!q||!(q->next))
		   {
			  return NULL;
		   }
		   p=head;
		   while(p!=q)
		   {
			   p=p->next;
			   q=q->next;
		   }
		   return p;
    }
};