class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(TrieNode* node, string &word, int index) {
        if (node == nullptr)
            return false;

        if (index == word.size())
            return node->isEnd;

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(node->child[i], word, index + 1))
                    return true;
            }
            return false;
        }

        return dfs(node->child[c - 'a'], word, index + 1);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->child[idx] == nullptr)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};