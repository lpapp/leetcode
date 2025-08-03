#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int ALPHABET_SIZE = 26;

struct TrieNode {
    vector<TrieNode*> children{ALPHABET_SIZE, nullptr};
    int wordIndex{-1};

    void insert(const string& word, int index) {
        TrieNode* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->wordIndex = index;
    }
};

class Solution {
    void dfs(TrieNode* node, int row, int col, vector<vector<char>>& board, vector<string>& foundWords, vector<string>& words, int rows, int cols) {
        const int charIndex = board[row][col] - 'a';
        if (!node->children[charIndex]) return;

        node = node->children[charIndex];
        if (node->wordIndex != -1) {
            foundWords.emplace_back(words[node->wordIndex]);
            node->wordIndex = -1;
        }

        int directions[5] = {-1, 0, 1, 0, -1};
        char tempChar = board[row][col];
        board[row][col] = '#';
        for (int k = 0; k < 4; ++k) {
            int x = row + directions[k], y = col + directions[k + 1];
            if (x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] != '#') {
                dfs(node, x, y, board, foundWords, words, rows, cols);
            }
        }

        board[row][col] = tempChar;
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trieRoot = new TrieNode();

        for (size_t i = 0; i < words.size(); ++i) trieRoot->insert(words[i], i);
        vector<string> foundWords;
        const size_t rows = board.size(), cols = board[0].size();

        for (size_t row = 0; row < rows; ++row) {
            for (size_t col = 0; col < cols; ++col) {
                dfs(trieRoot, row, col, board, foundWords, words, rows, cols);
            }
        }

        return foundWords;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> b1{
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'},
    };
    vector<string> w1{"oath", "pea", "eat", "rain"};
    
    const vector<string> r1 = solution.findWords(b1, w1);
    cout << "Result 1: ";
    for (const string& word : r1) cout << word << " ";
    cout << endl;
    
    vector<vector<char>> b2{
        {'a', 'b'},
        {'c', 'd'},
    };
    vector<string> w2{"abcb"};
    
    const vector<string> r2 = solution.findWords(b2, w2);
    cout << "Result 2: ";
    for (const string& word : r2) cout << word << " ";
    cout << endl;
    
    return 0;
}
