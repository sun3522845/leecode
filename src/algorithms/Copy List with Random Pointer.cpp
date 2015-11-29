/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,RandomListNode*> randomMap;
        RandomListNode * result = new RandomListNode(0);
        RandomListNode * tail = result;
        while(head){
            if(randomMap.count(head)==0){
                randomMap[head]=new RandomListNode(head->label);
            }
            tail->next = randomMap[head];
            tail=tail->next;
            if(!head->random){
                tail->random=NULL;
                head=head->next;
                continue;
            }
            if(randomMap.count(head->random)==0){
                randomMap[head->random]=new RandomListNode(head->random->label);
            }
            tail->random =  randomMap[head->random];
            head = head->next;
        }
        
        tail = result->next;
        delete result;
        return tail;
    }
};