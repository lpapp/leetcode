#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Time complexity: O(N ^ 3 * M)
// Space complexity: O(N ^ 2 * M)
// N: string length
// M: maximum word length in the dictionary

std::unordered_set<std::string> wordDictSet;

void printResult(const std::vector<std::string>& A)
{
  for (const std::string& s : A)
    std::cout << s << std::endl;
}

vector<string> wordBreakRecursive(const std::string& s)
{
  const std::size_t ssize = s.size();
  std::vector<std::vector<std::string>> dp(ssize);
  
  // s = catsanddog
  // i = 0, j = 1, right = c
  // i = 0, j = 2, right = ca
  // i = 0, j = 3, right = cat
  // ...
  // d[0] = [cat, cats]
  // i = 1, j = 2, right = a
  // i = 1, j = 3, right = at
  // i = 1, j = 4, right = ats
  // ...
  // dp= [[cat, cats], [], [], [sand], [and], [], [], [dog], [], []] 
  // dp[i] has all the dict words starting from i
  for (std::size_t i = 0; i < ssize; ++i) {
    std::vector<std::string> words;
    for (std::size_t j = i + 1; j <= ssize; ++j) {
      const std::string right = s.substr(i, j - i);
      if (wordDictSet.find(right) != wordDictSet.end())
        words.push_back(right);
    }
    dp[i] = words;
  }

  // s = catsanddog
  // i = 9, words = [] => result[9] = []
  // i = 8, words = [] => result[8] = []
  // i = 7, words = [dog] => result[7] = [dog]
  // i = 6, words = [] => result[6] = []
  // i = 5, words = [] => result[5] = []
  // i = 4, words = ["and dog"] => result[4] = ["and dog"]
  // i = 3, words = ["sand dog"] => result[3] = ["sand dog"]
  // i = 2, words = [] => result[2] = []
  // i = 1, words = [] => result[1] = []
  // i = 0, word: cat, word: cats => result[0] = [["cat sand dog"], ["cats and dog"]]
  std::vector<std::vector<std::string>> result(ssize);
  for (int i = ssize - 1; i >= 0; --i) {
    std::vector<std::string> words;
    for (auto word : dp[i]) {
      const std::size_t sword = word.size();
      const std::size_t end_of_word = i + sword;
      // word from i to the end of the string
      if (end_of_word == ssize) {
      	words.push_back(word);
      } else {
        for (auto w : result[end_of_word])
          words.push_back(word + " " + w);
      }
    }
    result[i] = words;
  }
  
  return result.front();
}

vector<string> wordBreak(string s, vector<string>& wordDict)
{
  wordDictSet.clear();
  wordDictSet.insert(wordDict.cbegin(), wordDict.cend());
  return wordBreakRecursive(s);
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

