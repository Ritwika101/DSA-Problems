class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }

};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        ListNode* p = head;
        priority_queue<ListNode*, vector<ListNode*>, compare>minheap;
        int k=lists.size();
        if(k==0) return NULL;
        for(int i=0;i<k;i++){
            ListNode* temp=lists[i];
            if(temp!=NULL)
               minheap.push(temp); 
        }
        while(!minheap.empty()){
            ListNode* temp=minheap.top();
            minheap.pop();
            if(!head){
                head=temp;
                p=temp;
            }
            else{
                p->next=temp;
                p=temp;
            }
            if(temp->next!=NULL)
                minheap.push(temp->next);
        }
        return head;
    }
};
