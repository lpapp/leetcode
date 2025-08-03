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

constexpr size_t ALPHABET_SIZE = 26;
 
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isLeaf{false};

    TrieNode()
    {
        for (size_t i = 0; i < ALPHABET_SIZE; ++i)
            children[i] = nullptr;
    }

    ~TrieNode()
    {
        for (size_t i = 0; i < ALPHABET_SIZE; ++i)
            delete children[i];
    }

    bool search(const string& s)
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
    void insert(const string& s)
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
        const size_t ssize = s.size();
    
        // Base case
        if (!ssize) return true;
    
        for (size_t i = 1; i <= ssize; ++i) {
            const string left = s.substr(0, i);
            const string right = s.substr(i, ssize - i);
            if (search(left) && wordBreak(right))
                return true;
        }
        
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        const size_t sWordDict = wordDict.size();
        for (size_t i = 0; i < sWordDict; ++i) root->insert(wordDict[i]);
        return root->wordBreak(s);
    }
};

int main()
{
    Solution solution;
    vector<string> wordDict = {
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
        cout << solution.wordBreak(s, wordDict) << endl;
    }

    string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict2 = {
        "a",
        "aa",
        "aaa",
        "aaaa",
        "aaaaa",
        "aaaaaa",
        "aaaaaaa",
        "aaaaaaaa",
        "aaaaaaaaa",
        "aaaaaaaaaa"
    };
    cout << solution.wordBreak(s2, wordDict2) << endl;

    return 0;
}

