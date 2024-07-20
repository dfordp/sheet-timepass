class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr=head,*end=head;
        while(end && end->next){
            curr=curr->next;
            end=end->next->next;
        }
        return curr;
    }
};