#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != static_cast<int>(s3.size())) return false;
        if (n > m) { swap(s1, s2); swap(m, n); }
        vector<char> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; ++j) dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; ++j) {
                const char fromS1 = dp[j] && s1[i - 1] == s3[i + j - 1];
                const char fromS2 = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                dp[j] = fromS1 || fromS2;
            }
        }
        return dp[n];
    }
};

int main()
{
	Solution s;
    assert(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(s.isInterleave("", "", ""));
	return 0;
}
