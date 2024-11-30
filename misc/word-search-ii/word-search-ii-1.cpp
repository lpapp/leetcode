#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Runtime Complexity: O(W * L + (R*C)^2) - building and searching.
// Building the trie:  O(W * L) - inserting each character of each word.
// Depth-First Search: O((R * C) * (R * C)) 
//
// Space complexity:   O(W * L + R * C) - trie and recursion stack.
// Trie:               O(W * L)
// Depth-First Search: O (R * C) - due to the recursive calls, which can be maximum R * C.
//
// R: the number of rows on the board.
// C: the number of columns on the board.
// W: the length of the word.
// L: average length of the words

constexpr std::size_t ALPHABET_SIZE = 26;

class TrieNode {
public:
  std::vector<std::unique_ptr<TrieNode>> children;
  int wordIndex;

  TrieNode() : children(ALPHABET_SIZE), wordIndex(-1) {}
  void insert(const std::string& word, int i) {
    TrieNode* node = this;
    for (const char c : word) {
      const std::size_t index = c - 'a';
      if (!node->children[index])
          node->children[index] = std::make_unique<TrieNode>();
      node = node->children[index].get();
    }
    node->wordIndex = i;
  }
};

class Solution {
  void dfs(std::vector<std::vector<char>>& board, const std::vector<std::string>& words, TrieNode* node, std::size_t row, std::size_t column, std::vector<std::string>& result) {
    const std::size_t rows = board.size();
    const std::size_t columns = board.front().size();
    if (row < 0 || column < 0 || row >= rows || column >= columns) return;

    const std::size_t charIndex = board[row][column] - 'a';
    if (!node->children[charIndex]) return;

    node = node->children[charIndex].get();
    if (node->wordIndex != -1) {
      result.push_back(words[node->wordIndex]);
      node->wordIndex = -1; // Do not look for this word again as it is already found
    }
 
    char& cell = board[row][column];
    const char originalCell = cell;
    // Mark the cell as visited.
    cell = '-';

    // Check in each adjacent (horizonal and vertical) directions.
    dfs(board, words, node, row - 1, column, result);
    dfs(board, words, node, row + 1, column, result);
    dfs(board, words, node, row, column - 1, result);
    dfs(board, words, node, row, column + 1, result);
  
    // Restore the original cell value to no longer mark it as visited.
    cell = originalCell;
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode rootNode;
    for (std::size_t i = 0; i < words.size(); ++i) {
      rootNode.insert(words[i], i);
    }

    std::vector<std::string> result;

    const std::size_t rows = board.size();
    const std::size_t columns = board.front().size();
    for (std::size_t row = 0; row < rows; ++row) {
      for (std::size_t column = 0; column < columns; ++column) {
        dfs(board, words, &rootNode, row, column, result);
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  std::vector<std::vector<char>> b1{
    {'o', 'a', 'a', 'n'},
    {'e', 't', 'a', 'e'},
    {'i', 'h', 'k', 'r'},
    {'i', 'f', 'l', 'v'},
  };
  std::vector<std::string> w1{"oath", "pea", "eat", "rain"};

  const std::vector<std::string> r1 = solution.findWords(b1, w1);
  std::cout << "Result 1: ";
  for (const std::string& word : r1)
    std::cout << word << " ";
  std::cout << std::endl;

  std::vector<std::vector<char>> b2{
    {'a', 'b'},
    {'c', 'd'},
  };
  std::vector<std::string> w2{"abcb"};

  const std::vector<std::string> r2 = solution.findWords(b2, w2);
  std::cout << "Result 2: ";
  for (const std::string& word : r2)
    std::cout << word << " ";
  std::cout << std::endl;

  return 0;
}
