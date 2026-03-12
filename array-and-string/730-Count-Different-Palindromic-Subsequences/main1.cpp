#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        constexpr int MOD = 1e9 + 7;
        const size_t sLength = s.size();
        vector<vector<array<uint64_t, 4>>> dp(sLength, vector<array<uint64_t, 4>>(sLength, {0}));
        for (size_t i = 0; i < sLength; ++i) dp[i][i][s[i] - 'a'] = 1;
      
        for (size_t length = 2; length <= sLength; ++length) {
            for (int start = 0; start + length <= sLength; ++start) {
                const int end = start + length - 1;
                for (char ch = 'a'; ch <= 'd'; ++ch) {
                    const size_t charIndex = ch - 'a';
                    if (s[start] == ch && s[end] == ch) {
                        uint64_t innerSum = 0;
                        for (size_t k = 0; k < 4; ++k) innerSum = (innerSum + dp[start + 1][end - 1][k]) % MOD;
                        dp[start][end][charIndex] = (2 + innerSum) % MOD;
                    } 
                    else if (s[start] == ch) dp[start][end][charIndex] = dp[start][end - 1][charIndex];
                    else if (s[end] == ch) dp[start][end][charIndex] = dp[start + 1][end][charIndex];
                    else dp[start][end][charIndex] = dp[start + 1][end - 1][charIndex];
                }
            }
        }
      
        uint64_t totalCount = 0;
        for (size_t k = 0; k < 4; ++k) totalCount = (totalCount + dp[0][sLength - 1][k]) % MOD;
        return static_cast<int>(totalCount % MOD);      
    }
};

int main()
{
	Solution s;
    cout << s.countPalindromicSubsequences("bccb") << endl;
    cout << s.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba") << endl;
	return 0;
}
