#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        const int sLength = s.size();
        vector<vector<int>> dp(sLength, vector<int>(sLength, 0));
        for (int length = 2; length <= sLength; ++length) {
            for (int left = 0; left <= sLength - length; ++left) {
                int right = left + length - 1; 
                if (s[left] == s[right]) dp[left][right] = dp[left + 1][right - 1];
                else dp[left][right] = min(dp[left + 1][right], dp[left][right - 1]) + 1;
            }
        }
        return dp[0][sLength - 1];
    }
};

int main()
{
	Solution s;
    cout << s.minInsertions("zzazz") << endl;
    cout << s.minInsertions("mbadm") << endl;
    cout << s.minInsertions("leetcode") << endl;
	return 0;
}
