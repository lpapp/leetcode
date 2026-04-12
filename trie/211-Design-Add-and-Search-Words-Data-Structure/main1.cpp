#include <array>
#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    array<TrieNode*, 26> children{nullptr};
    bool isWord{false};
    TrieNode() = default;
    void insert(const string& word) {
        TrieNode* node = this;
        for (const char c : word) {
            const size_t index = c - 'a';
            if (!node->children[index]) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isWord = true;
    }
};

class WordDictionary {
    TrieNode* root;
    bool dfs(const string& word, size_t index, const TrieNode* node) const {
        if (index == word.size()) return node->isWord;
        const char c = word[index];
        if (c != '.') {
            const size_t charIndex = c - 'a';
            TrieNode* child = node->children[charIndex];
            if (child && dfs(word, index + 1, child)) return true;
        }
        else {
            for (TrieNode* child : node->children) { if (child && dfs(word, index + 1, child)) return true; }
        }
        return false;
    }
public:
    WordDictionary() : root(new TrieNode()) {}
    void addWord(string word) { root->insert(word); }
    bool search(string word) const { return dfs(word, 0, root); }
};

int main()
{
	WordDictionary* wordDictionary = new WordDictionary();
	wordDictionary->addWord("bad");
	wordDictionary->addWord("dad");
	wordDictionary->addWord("mad");
	cout << wordDictionary->search("pad") << endl;
	cout << wordDictionary->search("bad") << endl;
	cout << wordDictionary->search(".ad") << endl;
	cout << wordDictionary->search("b..") << endl;
    return 0;
}
