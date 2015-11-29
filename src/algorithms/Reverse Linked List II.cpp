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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        	 ListNode * bfList,*headList;
		 bfList=NULL;
		 headList=head;
		for(int i =1; i<m;i++)
		{
			bfList = headList;
			headList = headList->next;
			
		}

		ListNode * tailList,*afList;
		tailList = headList;
		afList= tailList->next;
		for(int i = m ;i<n;i++)
		{
			ListNode *tmp = afList->next;
			afList->next = tailList;
			tailList = afList;
			afList=tmp;

		}

		headList->next = afList;
		if(bfList)
		{
			bfList->next = tailList;
			return head;
		}
		return tailList;
    }
};