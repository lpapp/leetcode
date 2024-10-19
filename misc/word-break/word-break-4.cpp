#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Optimised with Trie
// Time complexity: O(N * M)
//   N: string length of the string
//   M: longest word length in the dictionary. 
// Space complexity: O(N)

constexpr std::size_t ALPHABET_SIZE = 26;
 
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isLeaf{false};

    TrieNode()
    {
        for (std::size_t i = 0; i < ALPHABET_SIZE; ++i)
            children[i] = nullptr;
    }

    ~TrieNode()
    {
        for (std::size_t i = 0; i < ALPHABET_SIZE; ++i)
            delete children[i];
    }

    bool search(const std::string& s)
    {
        TrieNode* node = this;
        for (const char c : s) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
     
            node = node->children[index];
        }
     
        return node && node->isLeaf;
    }

    // Add the word to the trie if not present, and mark it as leaf.
    void insert(const std::string& s)
    {
        TrieNode* node = this;
        for (const char c : s) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
     
        node->isLeaf = true;
    }

    bool wordBreak(const string& s)
    {
        const std::size_t ssize = s.size();
    
        // Base case
        if (!ssize) return true;
    
        for (std::size_t i = 1; i <= ssize; ++i) {
            const std::string left = s.substr(0, i);
            const std::string right = s.substr(i, ssize - i);
            if (search(left) && wordBreak(right))
                return true;
        }
        
        return false;
    }
};

bool wordBreak(const std::string& s, const vector<string>& wordDict)
{
    TrieNode* root = new TrieNode();
    const std::size_t sWordDict = wordDict.size();
    for (std::size_t i = 0; i < sWordDict; ++i)
        root->insert(wordDict[i]);
    return root->wordBreak(s);
}

int main() {
    const vector<string> wordDict = {
        "and",
        "cream"
        "go", 
        "i",
        "ice",
        "icecream",
        "like",
        "man",
        "mango",
        "mobile",
        "sam", 
        "samsung",
        "sung",
    };

    for (const string& s: {"ilikesamsung", "iiiiiiii", "", "ilikelikeimangoiii", "samsungandmango", "samsungandmangok"}) {
        cout << wordBreak(s, wordDict) << endl;
    }

    return 0;
}

