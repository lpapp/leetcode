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
        if (n < m) { swap(s1, s2); swap(m, n); }
        vector<bool> dp(n + 1, false); dp[n] = true;
        for (int i = m; i >= 0; --i) {
            bool nextDp = i == m;
            for (int j = n; j >= 0; --j) {
                bool res = (j < n ? false : nextDp);
                if (i < m && s1[i] == s3[i + j] && dp[j]) res = true;
                if (j < n && s2[j] == s3[i + j] && nextDp) res = true;
                dp[j] = res;
                nextDp = dp[j];
            }
        }
        return dp[0];
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
