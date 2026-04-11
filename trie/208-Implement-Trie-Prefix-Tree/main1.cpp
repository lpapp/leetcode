#include <array>
#include <iostream>

using namespace std;

class Trie {
    array<Trie*, 26> children;
    bool isWord{false};
    const Trie* searchPrefix(string prefix) const {
        const Trie* node = this;
        for (const char c : prefix) {
            const size_t index = c - 'a';
            if (!node->children[index]) return nullptr;
            node = node->children[index];
        }
        return node;
    }
public:
    Trie() = default;
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            const size_t index = c - 'a';
            if (!node->children[index]) node->children[index] = new Trie();
            node = node->children[index];
        }
        node->isWord = true;   
    }
    bool search(string word) const { const Trie* node = searchPrefix(word); return node && node->isWord; }
    bool startsWith(string prefix) { return searchPrefix(prefix); }
};


int main()
{
	Trie* trie = new Trie();
	trie->insert("apple");
	cout << trie->search("apple") << endl;
	cout << trie->search("app") << endl;
	cout << trie->startsWith("app") << endl;
	trie->insert("app");
	cout << trie->search("app") << endl;
    return 0;
}
