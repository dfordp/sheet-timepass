class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> traversedNodes;
        ListNode *i=head;

        while(i!=NULL){
            if(traversedNodes.find(i) != traversedNodes.end()){ //element found
                return true;
            }
            else{
                traversedNodes.insert(i);
            }
            i=i->next;
        }
        return false;
    }
};