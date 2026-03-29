#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= i * i) dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    cout << s.numSquares(12) << endl;   
    cout << s.numSquares(13) << endl; 
    return 0;
}
