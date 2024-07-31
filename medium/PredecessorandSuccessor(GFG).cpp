class Solution
{
    public:
    void inorder(Node* root, vector<int> &vec){
        if(root== NULL) return;
        
        inorder(root->left, vec);
        vec.push_back(root->key);
        inorder(root->right, vec);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
            vector<int> vec;
            inorder(root, vec);
            pre = NULL;
            suc = NULL;
            for(int i=0; i<vec.size(); i++){
                      if (vec[i] < key) {
                        pre = new Node(vec[i]); 
                    }
                    if (vec[i] > key) {
                        suc = new Node(vec[i]);
                        break; 
                    }
            }
    }
};