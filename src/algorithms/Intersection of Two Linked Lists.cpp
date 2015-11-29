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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA;
        	ListNode *pb = headB;
		int lengthA(0),lengthB(0);
		while(pa)
		{
			pa=pa->next;
			lengthA++;
		}
		while(pb)
		{
			pb=pb->next;
			lengthB++;
		}
		pa = headA;
		pb = headB;
		if(lengthA<lengthB)
		{
			for(int i=0;i<(lengthB-lengthA);i++)
			{
				pb=pb->next;
			}
		}
		else
		{
			for(int i=0;i<(lengthA-lengthB);i++)
			{
				pa=pa->next;
			}
		}
		while(pa&&pb&&pa!=pb)
		{
			pa=pa->next;
			pb=pb->next;
		}
		return pa;
    }
};