class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val){
            l1->next=mergeList(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeList(l1,l2->next);;
            return l2;
        } 
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return head;
        }

        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next != NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        temp->next = NULL;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return mergeList(l1,l2);
    }
};