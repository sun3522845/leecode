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
    vector<ListNode *> heap;
    int numCounts;
    ListNode *tmp;
    void PushHeap(int nd){
        
        int i=nd;
        int t;
        while(2*i+2<numCounts){
            t=2*i+1;
            if(heap[t]->val>heap[t+1]->val ){
              t=t+1;
            }
            if(heap[i]->val>heap[t]->val){
                tmp=heap[i];
                heap[i]=heap[t];
                heap[t]=tmp;
                i=t;
            }
            else{
                return;
            }
            
        }
        if(2*i+2==numCounts && heap[i]->val>heap[numCounts-1]->val){
            tmp=heap[i];
            heap[i]=heap[numCounts-1];
            heap[numCounts-1]=tmp;
        }
        return;
    }
    
    void MakeHeap(vector<ListNode*>& lists){
        numCounts=0;
        for(vector<ListNode*>::iterator it=lists.begin();it!=lists.end();it++){
           if(*it){
            heap.push_back(*it);
            numCounts++;
           }
        }
        if(numCounts<2){
            return;
        }
        for(int i=numCounts/2-1;i>=0;i--){
            PushHeap(i);
        }
        return;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head=new ListNode(0);
        ListNode * tail=head;
     
        MakeHeap(lists);
        if(numCounts==0)
        {
            return NULL;
        }
        
        while(numCounts>1){
      
            tail->next=heap[0];
            tail=tail->next;
            if(heap[0]->next){
                heap[0]=heap[0]->next;
            }else{
                heap[0]=heap[numCounts-1];
                numCounts--;
            }
            PushHeap(0);
        }
        
        tail->next = heap[0];
        ListNode *result = head->next;
        delete head;
        return result;
    }
};