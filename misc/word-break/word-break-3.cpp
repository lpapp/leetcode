#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Optimised with memoization

bool wordBreak(string s, const vector<string>& wordDict)
{
    const std::size_t ssize = s.size();
    if (!ssize) return true;
    
    const unordered_set<string> wordDictSet(wordDict.cbegin(), wordDict.cend());

    // dp[i]: true if the prefix of length i can be segmented
    vector<bool> dp(ssize + 1, false);
    dp[0] = true; // Base case: empty string
    vector<int> memo{0};

    // string: icecream
    // ssize: 8
    // dictionary: [ice, cream]
    // dp[0] = true, dp[1...ssize] = false
    // i: 1, memo_size = 1, j = 0, last_valid_index = 0 => remaining = i
    // i: 2, memo_size = 1, j = 0, last_valid_index = 0 => remaining = ic
    // i: 3, memo_size = 1, j = 0, last_valid_index = 0 => remaining = ice, dp[3]=true, memo={0,3}
    // i: 4, memo_size = 2, j = 1, last_valid_index = 3 => remaining = c
    // i: 4, memo_size = 2, j = 0, last_valid_index = 0 => remaining = icec
    // i: 5, memo_size = 2, j = 1, last_valid_index = 3 => remaining = cr
    // i: 5, memo_size = 2, j = 0, last_valid_index = 0 => remaining = icecr
    // i: 6, memo_size = 2, j = 1, last_valid_index = 3 => remaining = cre
    // i: 6, memo_size = 2, j = 0, last_valid_index = 0 => remaining = icecre
    // i: 7, memo_size = 2, j = 1, last_valid_index = 3 => remaining = crea
    // i: 7, memo_size = 2, j = 0, last_valid_index = 0 => remaining = icecrea
    // i: 8, memo_size = 2, j = 1, last_valid_index = 3 => remaining = cream, dp[8]=true, memo={0,3,8}
    // Pattern: go through each prefix and then each prefix from left to right,
    // but only for indexes that were previously found to be segmentable, to
    // see if the prefix can be segmented into two valid words.
    for (std::size_t i = 1; i <= ssize; ++i) {
        const int memo_size = memo.size();
        for (int j = memo_size - 1; j >= 0; --j) {
            const int last_valid_index = memo[j];
            const string remaining = s.substr(last_valid_index, i - last_valid_index);
            const bool isValidDictWord = wordDictSet.find(remaining) != wordDictSet.end();
            if (isValidDictWord) {
                dp[i] = true;
                memo.push_back(i);
                break;
            }
        }
    }
    return dp[ssize];
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

