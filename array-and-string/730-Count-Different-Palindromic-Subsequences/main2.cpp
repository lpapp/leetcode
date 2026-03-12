#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        constexpr int MOD = 1e9 + 7;
        const size_t sLength = s.size();
        vector<vector<uint64_t>> dp(sLength, vector<uint64_t>(sLength, 0));

        for (size_t i = 0; i < sLength; ++i) dp[i][i] = 1;

        for (size_t length = 2; length <= sLength; ++length) {
            for (size_t i = 0; i <= sLength - length; ++i) {
                const size_t j = i + length - 1;
                if (s[i] == s[j]) dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % MOD;
                else dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]) % MOD;
            }
        }

        return static_cast<int>(dp[0][sLength-1] % MOD);
    }
};

int main()
{
	Solution s;
    cout << s.countPalindromicSubsequences("bccb") << endl;
    cout << s.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba") << endl;
	return 0;
}
