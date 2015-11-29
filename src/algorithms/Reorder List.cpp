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
    void reorderList(ListNode* head) {
              stack<ListNode *> st;
		ListNode * p = head;
		while(p)
		{
			st.push(p);
			p=p->next;
		}
		if(st.size()<3)
			return;
		p = head;
		while(!st.empty()&&st.top()!=p&&st.top()!=p->next)
		{
			ListNode *tmp = p->next;
			p->next = st.top();
			st.top()->next = tmp;
			p = tmp;
			st.pop();
		}
		if(st.top()==p->next)
		{
		    p = p->next;
		}
		p->next = NULL;
    }
};