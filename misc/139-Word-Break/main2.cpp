#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Dynamic Programming (iterative)
// Time complexity: O(N ^ 3 + M)
// Space complexity: O(N + M)
// N: string length
// M: dict length

bool wordBreak(string s, const vector<string>& wordDict)
{
    const unordered_set<string> wordDictSet(wordDict.cbegin(), wordDict.cend());

    const std::size_t ssize = s.size();
    
    // dp[i]: true if the prefix of length i can be segmented
    vector<bool> dp(ssize + 1, false);
    dp[0] = true; // Base case: empty string
 
    // string: icecream
    // ssize: 8
    // dictionary: [ice, cream]
    // dp[0] = true, dp[1...ssize] = false
    // i: 1, j = 0 => remaining = i
    // i: 2, j = 0 => remaining = ic
    // i: 2, j = 1 => remaining = c
    // i: 3, j = 0 => remaining = ice => dp[3] = true
    // i: 4, j = 0 => remaining = icec
    // i: 4, j = 1 => remaining = cec
    // i: 4, j = 2 => remaining = ec
    // i: 4, j = 3 => remaining = c
    // i: 5, j = 0 => remaining = icecr
    // ...
    // i: 6, j = 0 => remaining = icecre
    // ...
    // i: 7, j = 0 => remaining = icecrea
    // ...
    // i: 8, j = 0 => remaining = icecream
    // ...
    // i: 8, j = 3 => remaining = cream => dp[8] (Resolved)
    // Pattern: go through each prefix and then each prefix from left to right
    // to see if the prefix can be segmented into two valid words.
    for (std::size_t i = 1; i <= ssize; ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            const string remaining = s.substr(j, i - j);
            const bool isValidDictWord = wordDictSet.find(remaining) != wordDictSet.end();
            if (dp[j] && isValidDictWord) {
                dp[i] = true;
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

