#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        const int n = stones.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stones[i];
        vector<int> dp(n, 0);
        for (int len = 2; len <= n; ++len) for (int i = 0, j = len - 1; j < n; ++i, ++j) dp[i] = max(prefix[j + 1] - prefix[i + 1] - dp[i + 1], prefix[j] - prefix[i] - dp[i]);
        return dp[0];
    }
};

int main()
{
    Solution s;
    vector<int> stones1 = {5, 3, 1, 4, 2};
    assert(s.stoneGameVII(stones1) == 6);
    vector<int> stones2 = {7, 90, 5, 1, 100, 10, 10, 2};
    assert(s.stoneGameVII(stones2) == 122);
    return 0;
}
