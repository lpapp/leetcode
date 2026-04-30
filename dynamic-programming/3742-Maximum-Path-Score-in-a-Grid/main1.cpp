#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector dp(m, vector(n, vector<int>(k + 1, -1)));
        dp[0][0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                int score = grid[i][j], cost = score > 0;
                for (int c = cost; c <= k; ++c) {
                    int maxScore = -1;
                    if (i > 0 && dp[i - 1][j][c - cost] >= 0) maxScore = max(maxScore, dp[i - 1][j][c - cost]);
                    if (j > 0 && dp[i][j - 1][c - cost] >= 0) maxScore = max(maxScore, dp[i][j - 1][c - cost]);
                    if (maxScore >= 0) dp[i][j][c] = maxScore + score;
                }
            }
        }
        int ans = ranges::max(dp[m - 1][n - 1]);
        return ans < 0 ? -1 : ans;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> grid1 = {
        {0, 1},
        {2, 0}
    };
    cout << s.maxPathScore(grid1, 1) << endl;
    vector<vector<int>> grid2 = {
        {0, 1},
        {1, 2}
    };
    cout << s.maxPathScore(grid2, 1) << endl;
	return 0;
}
