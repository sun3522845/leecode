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
    ListNode* deleteDuplicates(ListNode* head) {
             
        if(!head)
            return head;
                
        ListNode * p = head->next;
		ListNode * q = new ListNode(0);
		q->next = head;
		head = q;
		bool hasDup=false;
		while(p)
		{
			if(p->val == q->next->val)
			{
				p = p->next;
				hasDup =true;
			}
			else 
			{
			    
			    if(hasDup)
				{
    				while(q->next!=p)
    				{
    					ListNode * tmp = q->next;
    					q->next=tmp->next;
    					delete tmp;
    				}
    				hasDup =false;
				}
				else
				{
				    q = q->next;
				}
			   
				p=p->next;
			}
		}
		 if(hasDup)
		{
			while(q->next!=p)
			{
				ListNode * tmp = q->next;
				q->next=tmp->next;
				delete tmp;
			}
			hasDup =false;
		}

		p = head ->next;
		delete head;
		return p;
    }
};