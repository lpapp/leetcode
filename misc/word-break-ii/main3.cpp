#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Time complexity: O(N ^ 3 * M)
// Space complexity: O(N ^ 2 * M)
// N: string length
// M: maximum word length in the dictionary

constexpr int ALPHABET_SIZE = 26;

// Trie data structure for efficient word storage and retrieval
struct TrieNode {
    // Array representing the children of each node
    vector<unique_ptr<TrieNode>> children{ALPHABET_SIZE};

    // Flag to indicate the end of a word
    bool isEndOfWord{false};

    // Method to insert a word into the trie
    void insert(const string& word) {
        TrieNode* currentNode = this;

        for (const char ch : word) {
            const int index = ch - 'a';
            if (!currentNode->children[index]) currentNode->children[index] = make_unique<TrieNode>();

            currentNode = currentNode->children[index].get();
        }

        currentNode->isEndOfWord = true;
    }

    // Method to search for a word in the trie
    bool search(const string& word) {
        TrieNode* currentNode = this;
        for (const char ch : word) {
            const int index = ch - 'a';
            if (!(currentNode->children[index])) return false;
            currentNode = currentNode->children[index].get();
        }

        return currentNode->isEndOfWord;
    }
};

class Solution {
    // Create a root trie node
    TrieNode rootTrieNode;

    // Method for depth-first search to find word break combinations
    vector<vector<string>> depthFirstSearch(const string& s) {
        vector<vector<string>> results;

        // If the string is empty, add an empty list (base case)
        if (s.empty()) {
            results.emplace_back();
            return results;
        }

        // Try breaking the string at different points to find valid words
        for (size_t i = 1; i <= s.length(); ++i) {

            // Check if the prefix is a valid word
            if (rootTrieNode.search(s.substr(0, i))) {

                // Recursively process the remaining string
                for (vector<string> suffixCombination : depthFirstSearch(s.substr(i))) {

                    // Add the valid word to the beginning of the list
                    suffixCombination.insert(suffixCombination.begin(), s.substr(0, i));

                    // Add the new combination to the results
                    results.push_back(suffixCombination);
                }
            }
        }
        return results;
    }

    // Helper function to concatenate vector of strings with a delimiter
    string join(const vector<string>& words, const string& delimiter) {
        string sentence;
        for (size_t i = 0; i < words.size(); ++i) {
            sentence += words[i];
            if (i < words.size() - 1) sentence += delimiter;
        }
        return sentence;
    }

public:
    // Main method to find all possible word breaks
    vector<string> wordBreak(const string& s, const vector<string>& wordDict) {
        // Insert all words from the dictionary into the trie
        for (const string &word : wordDict) rootTrieNode.insert(word);

        // Perform a depth-first search to find all combinations
        vector<vector<string>> combinations = depthFirstSearch(s);

        // Convert lists of strings into space-separated sentences
        vector<string> result;
        for (const vector<string>& words : combinations) result.push_back(join(words, " "));
        return result;
    }
};

void printResult(const vector<string>& A)
{
    for (const string& s : A) cout << s << endl;
}

int main()
{
    Solution solution;
    vector<string> wordDict = {
        "and",
        "cat",
        "cats",
        "dog",
        "sand",
    };
    
    printResult(solution.wordBreak("catsanddog", wordDict));
    return 0;
}

