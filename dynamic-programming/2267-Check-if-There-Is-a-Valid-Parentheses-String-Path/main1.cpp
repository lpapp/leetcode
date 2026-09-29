#include <bitset>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) & 1) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        vector<bitset<200>> dp(n); dp[0][1] = 1;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c) {
                if (!r && !c) continue;
                bitset<200> reach;
                if (r) reach |= dp[c];
                if (c) reach |= dp[c - 1];
                dp[c] = grid[r][c] == '(' ? (reach << 1) : (reach >> 1);
            }
        return dp[n - 1][0];
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid1 = {
        {'(', '(', '('},
        {')', '(', ')'},
        {'(', '(', ')'},
        {'(', '(', ')'}
    };
    assert(s.hasValidPath(grid1));
    vector<vector<char>> grid2 = {
        {')', ')'},
        {'(', '('}
    };
    assert(!s.hasValidPath(grid2));
    return 0;
}
