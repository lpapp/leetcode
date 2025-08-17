#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(row*column)
// Space complexity: O(row*column) - could reduce the memory usage by only
// keeping the current row in memory.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const size_t rows = obstacleGrid.size();
        const size_t columns = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        for (size_t row = 0; row < rows && obstacleGrid[row][0] == 0; ++row) dp[row][0] = 1;
        for (size_t column = 0; column < columns && obstacleGrid[0][column] == 0; ++column) dp[0][column] = 1;

        for (size_t row = 1; row < rows; ++row) {
            for (size_t column = 1; column < columns; ++column) {
                if (!obstacleGrid[row][column]) dp[row][column] = dp[row - 1][column] + dp[row][column - 1];

            }
        }

        return dp[rows - 1][columns - 1];       
    }
};

int main()
{
	Solution solution;
	vector<vector<int>> input1 = {{0,0,0}, {0,1,0}, {0,0,0}};
	cout << solution.uniquePathsWithObstacles(input1) << endl;

	vector<vector<int>> input2 = {{0,1},{0,0}};
	cout << solution.uniquePathsWithObstacles(input2) << endl;
	return 0;
}
