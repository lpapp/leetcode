#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int rows = grid.size(), columns = grid[0].size();
    	for (int i = 1; i < rows; ++i) grid[i][0] += grid[i - 1][0];
    	for (int j = 1; j < columns; ++j) grid[0][j] += grid[0][j - 1];
    	for (int i = 1; i < rows; ++i) for (int j = 1; j < columns; ++j) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
    	return grid[rows - 1][columns - 1];
    }
};

int main()
{
	Solution s;
    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    assert(s.minPathSum(grid1) == 7);
    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    assert(s.minPathSum(grid2) == 12);
	return 0;
}
