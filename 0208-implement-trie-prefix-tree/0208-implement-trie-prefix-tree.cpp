
class TrieNode {
    public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        }

        void insert(string word){
            TrieNode* node=root;
            for(char c: word){
                int idx=c-'a';
                if(node->child[idx]==nullptr){
                    node->child[idx]=new TrieNode();
                }
                node=node->child[idx];
            }
            node->isEnd=true;
        }
        
        bool search( string word){
            TrieNode* node=root;
            for(char c: word){
                int idx=c-'a';
                if(node->child[idx]==nullptr){
                    return false;
                }
                node=node->child[idx];
            }
            return node->isEnd;
        }

        bool startsWith(string word){
            TrieNode* node=root;
            for(char c: word){
                int idx=c-'a';
                if(node->child[idx]==nullptr){
                    return false;
                }
                node=node->child[idx];
            }
            return true;

        }

};

