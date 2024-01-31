class TrieNode {
public:
    char value;
    vector<TrieNode*> children; 
    bool isEndOfWord;
    TrieNode(char value) {
        this->value = value;
        this->isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode* root, string word) {
        if (word.empty()) {
            root->isEndOfWord = true;
            return;
        }
        char ch = word[0];
        auto it = find_if(root->children.begin(), root->children.end(), [&ch](TrieNode* node) {
            return node->value == ch;
        });
        TrieNode* temp;
        if (it != root->children.end()) {
            temp = *it;
        } else {
            temp = new TrieNode(ch);
            root->children.push_back(temp);
        }
        insertHelper(temp, word.substr(1));
    }

    void insert(string word) {
        insertHelper(root, word);
    }

    bool searchHelper(TrieNode* root, string word) {
        if (word.empty()) return root->isEndOfWord;
        char ch = word[0];
        auto it = find_if(root->children.begin(), root->children.end(), [&ch](TrieNode* node) {
            return node->value == ch;
        });
        if (it != root->children.end()) {
            return searchHelper(*it, word.substr(1));
        }
        return false;
    }

    bool search(string word) {
        return searchHelper(root, word);
    }

    bool startsWithHelper(TrieNode* root, string word) {
        if (word.empty()) return true;
        char ch = word[0];
        auto it = find_if(root->children.begin(), root->children.end(), [&ch](TrieNode* node) {
            return node->value == ch;
        });
        if (it != root->children.end()) {
            return startsWithHelper(*it, word.substr(1));
        }
        return false;
    }

    bool startsWith(string prefix) {
        return startsWithHelper(root, prefix);
    }
};
