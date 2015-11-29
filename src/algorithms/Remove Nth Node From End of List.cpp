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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode * beg = head;
	ListNode * end = head;
	int i=0;
	while(end&&i<n)
	{
		end=end->next;
		i++;
	}
	
	if(i<n)
		return head;
	else if(!end)
	{
		ListNode* node = head;
		head= head->next;
		delete node;
		return head;
	}
	while(end->next)
	{
		beg=beg->next;
		end=end->next;
	}

	ListNode* node = beg->next;
	beg->next=beg->next->next;
	delete node;
	return head;
    }
};