#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Time complexity: O(2 ^ N)
// Space complexity: O(S + M)
//   N: string length
//   M: length of all the characters in the dict

std::unordered_map<std::string, std::vector<std::string>> memo;
std::unordered_set<std::string> wordDictSet;

void printResult(const std::vector<std::string>& A)
{
  for (const std::string& s : A)
    std::cout << s << std::endl;
}

vector<string> wordBreakRecursive(const std::string& s)
{ 
  if (memo.find(s) != memo.end())
    return memo[s];
  
  std::vector<std::string> result;
  
  if (wordDictSet.find(s) != wordDictSet.end())
    result.push_back(s);
  
  for (std::size_t i = 1; i < s.length(); ++i) {
    const std::string right = s.substr(i);
    if (wordDictSet.find(right) != wordDictSet.end()) {
      const std::string left = s.substr(0, i);
      for (const std::string& sentence : wordBreakRecursive(left)) {
        result.push_back(sentence + " " + right);
      }
    }
  }
  
  memo[s] = result;
  return result;
}

vector<string> wordBreak(string s, vector<string>& wordDict)
{
  memo.clear();
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

