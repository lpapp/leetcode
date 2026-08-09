#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) suffix[i] = suffix[i + 1] + piles[i];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) for (int m = 1; m <= n; ++m) {
            if (2 * m >= n - i) { dp[i][m] = suffix[i]; continue; }
            for (int x = 1, limit = 2 * m; x <= limit; ++x) dp[i][m] = max(dp[i][m], suffix[i] - dp[i + x][max(m, x)]);
        }
        return dp[0][1];
    }
};

int main()
{
    Solution s;
    vector<int> piles1 = {2, 7, 9, 4, 4};
    assert(s.stoneGameII(piles1) == 10);
    vector<int> piles2 = {1, 2, 3, 4, 5, 100};
    assert(s.stoneGameII(piles2) == 104);
    return 0;
}
