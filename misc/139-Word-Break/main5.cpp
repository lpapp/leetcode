#include <cassert>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    struct StringHash {
        using is_transparent = void;
        size_t operator()(string_view sv) const { return hash<string_view>{}(sv); }
    };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const unordered_set<string, StringHash, equal_to<>> words(wordDict.cbegin(), wordDict.cend());
        int maxLen = 0;
        for (const string& word : wordDict) maxLen = max(maxLen, static_cast<int>(word.size()));
        const int n = s.size();
        vector<int> memo{0};
        vector<char> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int idx = memo.size() - 1; idx >= 0; --idx) {
                const int j = memo[idx];
                if (i - j > maxLen) break;
                if (words.contains(string_view(s).substr(j, i - j))) { dp[i] = true; memo.push_back(i); break; 
}
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    vector<string> wordDict1 = {"leet", "code"};
    assert(s.wordBreak("leetcode", wordDict1));
    vector<string> wordDict2 = {"apple", "pen"};
    assert(s.wordBreak("applepenapple", wordDict2));
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    assert(!s.wordBreak("catsandog", wordDict2));
    return 0;
}
