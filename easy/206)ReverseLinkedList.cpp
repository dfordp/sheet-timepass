class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* n,*prev=NULL;
        while(head){
            n=head->next;
            head->next=prev;
            prev=head;
            head=n;
        }
        return prev;
    }
};