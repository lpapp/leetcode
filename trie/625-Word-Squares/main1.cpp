#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
    array<Trie*, 26> children{nullptr};
    vector<int> indices;
public:
    Trie() = default;
    void insert(const string& word, int index) {
        Trie* node = this;
        for (const char c : word) {
            const size_t cIndex = c - 'a';
            if (!node->children[cIndex]) node->children[cIndex] = new Trie();
            node = node->children[cIndex];
            node->indices.push_back(index);
        }
    }
    vector<int> search(const string& prefix) const {
        const Trie* node = this;
        for (const char c : prefix) {
            const size_t cIndex = c - 'a';
            if (!node->children[cIndex]) return {};
            node = node->children[cIndex];
        }
        return node->indices;
    }
};

class Solution {
private:
    Trie* root{nullptr};
    vector<string> m_words;
    vector<vector<string>> result;

    void dfs(vector<string>& square) {
        if (square.size() == m_words[0].length()) { result.push_back(vector<string>(square)); return; }
        string prefix = "";
        for (const string& word : square) prefix += word[square.size()];
        for (const size_t wordIndex : root->search(prefix)) {
            square.push_back(m_words[wordIndex]);
            dfs(square);
            square.pop_back();
        }
    }
public:
    Solution() = default;
    vector<vector<string>> wordSquares(vector<string>& words) {
        m_words = words;
        result.clear();
        if (root) delete root;
        root = new Trie();
        for (size_t i = 0; i < m_words.size(); i++) root->insert(words[i], i);
        vector<string> square;
        for (const string& word : m_words) {
            square.push_back(word);
            dfs(square);
            square.pop_back();
        }
        return result;
    }
};

void printVectorVector(const vector<vector<string>>& input)
{
    cout << "[";
    for (const vector<string>& v: input) {
        cout << "[";
        for (const string& s: v) {
            cout << s << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<string> words1 = {"ball", "area", "lead", "lady"};
    printVectorVector(s.wordSquares(words1));
    return 0;
}
