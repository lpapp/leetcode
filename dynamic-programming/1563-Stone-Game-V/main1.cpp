#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> prefix(n + 1);
        partial_sum(cbegin(stoneValue), cend(stoneValue), begin(prefix) + 1);
        vector<vector<int>> mid(n, vector<int>(n));
        for (int l = 1; l <= n; ++l) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                int p = (l == 1) ? i : mid[i][j - 1];
                while (prefix[p] - prefix[i] < prefix[j + 1] - prefix[p]) ++p;
                mid[i][j] = p;
            }
        }
        vector<vector<int>> rmq(n, vector<int>(n));
        for (int i = 0; i < n; ++i) rmq[i][i] = stoneValue[i];
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = 2; l <= n; ++l) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                const int p = mid[i][j];
                int maxScore = 0;
                if (prefix[p] - prefix[i] == prefix[j + 1] - prefix[p]) maxScore = max(rmq[i][p - 1], rmq[j][p]);
                else {
                    if (i <= p - 2) maxScore = max(maxScore, rmq[i][p - 2]);
                    if (p <= j) maxScore = max(maxScore, rmq[j][p]);
                }
                dp[i][j] = maxScore;
                rmq[i][j] = max(rmq[i][j - 1], (prefix[j + 1] - prefix[i]) + maxScore);
                rmq[j][i] = max(rmq[j][i + 1], (prefix[j + 1] - prefix[i]) + maxScore);
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    Solution s;
    vector<int> stoneValue1 = {6, 2, 3, 4, 5, 5};
    assert(s.stoneGameV(stoneValue1) == 18);
    vector<int> stoneValue2 = {7, 7, 7, 7, 7, 7, 7};
    assert(s.stoneGameV(stoneValue2) == 28);
    vector<int> stoneValue3 = {4};
    assert(!s.stoneGameV(stoneValue3));
    return 0;
}
