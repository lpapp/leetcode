#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; ++i) for (int k = 1; k * k <= i; ++k) if (!dp[i - k * k]) { dp[i] = true; break; }
        return dp[n];
    }
};

int main()
{
    Solution s;
    assert(s.winnerSquareGame(1));
    assert(!s.winnerSquareGame(2));
    assert(s.winnerSquareGame(4));
    return 0;
}
