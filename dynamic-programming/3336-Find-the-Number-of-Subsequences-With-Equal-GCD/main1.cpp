#include <algorithm>
#include <cassert>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1'000'000'007, m = ranges::max(nums);
        vector<vector<int>> dp(m + 1, vector<int>(m + 1)); dp[0][0] = 1;
        for (const int num : nums) {
            vector<vector<int>> next(m + 1, vector<int>(m + 1));
            for (int x = 0; x <= m; ++x)
                for (int y = 0; y <= m; ++y) {
                    if (!dp[x][y]) continue;
                    const int v = dp[x][y], nx = gcd(x, num), ny = gcd(y, num);
                    next[x][y] = (next[x][y] + v) % MOD;
                    next[nx][y] = (next[nx][y] + v) % MOD;
                    next[x][ny] = (next[x][ny] + v) % MOD;
                }
            dp = std::move(next);
        }

        int res = 0;
        for (int g = 1; g <= m; ++g) res = (res + dp[g][g]) % MOD;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4};
    assert(s.subsequencePairCount(nums1) == 10);
    vector<int> nums2 = {10, 20, 30};
    assert(s.subsequencePairCount(nums2) == 2);
    vector<int> nums3 = {1, 1, 1, 1};
    assert(s.subsequencePairCount(nums3) == 50);
    return 0;
}
