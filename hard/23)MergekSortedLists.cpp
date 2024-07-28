class Solution {
public:
     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()){
            return nullptr;
        }
        return helper(lists , 0 , lists.size()-1);
    }
    
    ListNode* helper(vector<ListNode*>& lists, int start , int end){
        if(start==end){
            return lists[start];
        }

        int mid = start + (end-start)/2;
        ListNode* l1 = helper(lists,start,mid);
        ListNode* l2 = helper(lists,mid+1,end);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeTwoLists(ListNode *l1,ListNode* l2){
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }

    }
};