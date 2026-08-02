#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = piles[i];
            for (int j = i + 1; j < n; ++j) dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
        }
        return dp[n - 1] >= 0;       
    }
};

int main()
{
    Solution s;
    vector<int> piles1 = {5, 3, 4, 5};
    assert(s.stoneGame(piles1));
    vector<int> piles2 = {3, 7, 2, 3};
    assert(s.stoneGame(piles2));
    return 0;
}
