class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }

        ListNode* t1=head;
        ListNode* t2=head;

        for (int i = 0; i < n; ++i)
            t2 = t2->next;

        if(t2==NULL){
            return head->next;
        }

        while(t2->next!=NULL){
            t2=t2->next;
            t1=t1->next;
        }

        t1->next=t1->next->next;

        return head;
    }
};