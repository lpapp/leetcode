#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string concatenatedString = word1 + word2;
        const size_t concatenatedLength = concatenatedString.size();
        vector<vector<int>> dp(concatenatedLength, vector<int>(concatenatedLength, 0));
        for (size_t i = 0; i < concatenatedLength; ++i) dp[i][i] = 1;
        int maxPalindromeLength = 0;
        for (int left = concatenatedLength - 2; left >= 0; --left) {
            for (size_t right = left + 1; right < concatenatedLength; ++right) {
                if (concatenatedString[left] == concatenatedString[right]) {
                    dp[left][right] = dp[left + 1][right - 1] + 2;
                    if (left < static_cast<int>(word1.size()) && right >= word1.size()) maxPalindromeLength = max(maxPalindromeLength, dp[left][right]);
                } else {
                    dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
                }
            }
        }
      
        return maxPalindromeLength;
    }
};

int main()
{
	Solution s;
    cout << s.longestPalindrome("cacb", "cbba") << endl;
    cout << s.longestPalindrome("ab", "ab") << endl;
    cout << s.longestPalindrome("aa", "bb") << endl;
	return 0;
}
