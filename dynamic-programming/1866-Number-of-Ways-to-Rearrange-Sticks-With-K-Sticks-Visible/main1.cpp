#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<long long> dp(k + 1, 0); dp[0] = 1;
        for (int i = 1, MOD = 1'000'000'007; i <= n; ++i) {
            for (int j = min(i, k); j >= 1; --j) dp[j] = (dp[j - 1] + (long long)(i - 1) * dp[j]) % MOD;
            dp[0] = 0;
        }
        return dp[k];
    }
};

int main()
{
    Solution s;
    assert(s.rearrangeSticks(3, 2) == 3);
    assert(s.rearrangeSticks(5, 5) == 1);
    assert(s.rearrangeSticks(20, 11) == 647427950);
    return 0;
}
