class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dum = new ListNode(0,head);
        ListNode *prev=dum;
        ListNode* t1=head;

        while(t1){
            if(t1->next && t1->val==t1->next->val){
                while(t1->next&& t1->val==t1->next->val){
                    t1=t1->next;
                }
                prev->next=t1->next;
                delete t1;
                t1=prev;
            }
            else{
                prev=prev->next;
            }
            t1=t1->next;
        }
        return dum->next;
    }
};