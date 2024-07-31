class BSTIterator {
    stack<TreeNode*> s;

    void pushAll(TreeNode *node){
        for(;node!=NULL;node = node->left){
            s.push(node);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* curr = s.top();
        s.pop();
        pushAll(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
