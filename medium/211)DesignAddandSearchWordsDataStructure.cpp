class TrieNode{
    public:
        bool isWord;
        TrieNode *child[26];
        TrieNode(){
            isWord=false;
            for(auto &a:child) a = nullptr;
        }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *p= root;
        for(auto &a:word){
            int i=a-'a';
            if(!p->child[i]) p->child[i]= new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        return search(word.c_str(),root);
    }

    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++){
            if (word[i] != '.') {
                node = node -> child[word[i] - 'a'];
            }
            else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> child[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> isWord;
    }
};
