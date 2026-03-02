#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const size_t sLength = s.size();
        vector<vector<bool>> dp(sLength, vector<bool>(sLength, true));
        size_t startIndex = 0, maxLength = 1;
        for (int i = sLength - 2; i >= 0; --i) {
            for (size_t j = i + 1; j < sLength; ++j) {
                dp[i][j] = false;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j] && maxLength < j - i + 1) {
                        maxLength = j - i + 1;
                        startIndex = i;
                    }
                }
            }
        }
      
        return s.substr(startIndex, maxLength);   
    }
};

int main()
{
	Solution s;
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
	return 0;
}
