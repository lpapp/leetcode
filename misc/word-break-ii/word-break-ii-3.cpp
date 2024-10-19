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

// Trie data structure for efficient word storage and retrieval

constexpr std::size_t ALPHABET_SIZE = 26;

class TrieNode {
  std::vector<std::unique_ptr<TrieNode>> children;
  bool isEndOfWord;

public:
  TrieNode() : children(ALPHABET_SIZE), isEndOfWord(false) {}
  void insert(const std::string& word) {
    TrieNode* node = this;
    for (const char c : word) {
      const std::size_t index = c - 'a';
      if (!node->children[index])
          node->children[index] = std::make_unique<TrieNode>();
      node = node->children[index].get();
    }
    node->isEndOfWord = true;
  }

  bool search(const std::string& word) {
    TrieNode* node = this;
    for (const char c : word) {
      const std::size_t index = c - 'a';
      if (!(node->children[index])) {
          return false;
      }
      node = node->children[index].get();
    }
    return node->isEndOfWord;
  }

  std::vector<std::vector<std::string>> depthFirstSearch(const std::string &s) {
    std::vector<std::vector<std::string>> result;
    if (s.empty()) {
      result.emplace_back();
      return result;
    }

    for (std::size_t i = 1; i <= s.length(); ++i) {
      const std::string left = s.substr(0, i);
      if (search(left)) {
        const std::string right = s.substr(i);
        for (auto rightResult : depthFirstSearch(right)) {
          rightResult.insert(rightResult.begin(), left);
          result.push_back(rightResult);
        }
      }
    }

    return result;
  }
};

std::string join(const std::vector<std::string>& words, const std::string& delimiter)
{
  std::string result = std::accumulate(std::next(words.begin()), words.end(),
      words.front(),
      [&delimiter](const std::string& a, const std::string& b) {
      return a + delimiter + b;
  });
  return result;
}

vector<string> wordBreak(string s, vector<string>& wordDict)
{
  TrieNode root;
  for (const std::string& word : wordDict) {
    root.insert(word);
  }
  
  const std::vector<std::vector<std::string>> results = root.depthFirstSearch(s);
  
  std::vector<std::string> result;
  for (const std::vector<std::string>& words : results) {
    result.push_back(join(words, " "));
  }
  
  return result;
}

void printResult(const std::vector<std::string>& A)
{
  for (const std::string& s : A)
    std::cout << s << std::endl;
}

int main()
{
  vector<string> wordDict = {
    "and",
    "cat",
    "cats",
    "dog",
    "sand",
  };

  printResult(wordBreak("catsanddog", wordDict));
  return 0;
}

