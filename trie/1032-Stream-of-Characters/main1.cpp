#include <cassert>
#include <string>
#include <vector>

using namespace std;

class StreamChecker {
    static constexpr int LIMIT = 201;
    struct TrieNode {
        TrieNode* children[26]{};
        bool isEnd = false;
    };
    TrieNode root;
    string stream;
    void insert(const string& word) {
        TrieNode* node = &root;
        for (int i = word.size() - 1; i >= 0; --i) {
            const int idx = word[i] - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
public:
    StreamChecker(vector<string>& words) { for (const string& word : words) insert(word); }
    bool query(char letter) {
        stream += letter;
        if (static_cast<int>(stream.size()) > LIMIT) stream.erase(0, stream.size() - LIMIT);
        TrieNode* node = &root;
        for (int i = stream.size() - 1; i >= 0; --i) {
            const int idx = stream[i] - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
            if (node->isEnd) return true;
        }
        return false;
    }
};

int main()
{
    vector<string> words1 = {"cd", "f", "kl"};
    StreamChecker streamChecker(words1);
    assert(!streamChecker.query('a'));
    assert(!streamChecker.query('b'));
    assert(!streamChecker.query('c'));
    assert(streamChecker.query('d'));
    assert(!streamChecker.query('e'));
    assert(streamChecker.query('f'));
    assert(!streamChecker.query('g'));
    assert(!streamChecker.query('h'));
    assert(!streamChecker.query('i'));
    assert(!streamChecker.query('j'));
    assert(!streamChecker.query('k'));
    assert(streamChecker.query('l'));
    return 0;
}
