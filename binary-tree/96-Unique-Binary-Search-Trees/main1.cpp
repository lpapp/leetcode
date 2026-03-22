#include <iostream>
#include  <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1); dp[0] = 1;
        for (int nodes = 1; nodes <= n; ++nodes) {
            for (int left = 0; left < nodes; ++left) dp[nodes] += dp[left] * dp[nodes - left - 1];
        }
        return dp[n];
    }
};

int main()
{
	Solution solution;
	cout << solution.numTrees(3) << endl;
	cout << solution.numTrees(1) << endl;
	return 0;
}
