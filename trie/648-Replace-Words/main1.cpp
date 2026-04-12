#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Trie {
    array<Trie*, 26> children{nullptr};
    int m_index{-1};
public:
    Trie() = default;
    void insert(const string& word, int index) {
        Trie* node = this;
        for (const char c : word) {
            const size_t cIndex = c - 'a';
            if (!node->children[cIndex]) node->children[cIndex] = new Trie();
            node = node->children[cIndex];
        }
        node->m_index = index;
    }
    int search(const string& word) const {
        const Trie* node = this;
        for (const char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return -1;
            node = node->children[index];
            if (node->m_index != -1) return node->m_index;
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for (size_t i = 0; i < dictionary.size(); ++i) root->insert(dictionary[i], i);
        stringstream ss(sentence);
        string word, result;
        while (ss >> word) { const int index = root->search(word); result += ((index == -1) ? word : dictionary[index]) + " "; }
        result.pop_back();
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> dictionary1 = {"cat", "bat", "rat"};
    cout << s.replaceWords(dictionary1, "the cattle was rattled by the battery") << endl;
    vector<string> dictionary2 = {"a", "b", "c"};
    cout << s.replaceWords(dictionary2, "aadsfasf absbs bbab cadsfafs") << endl;
    return 0;
}
