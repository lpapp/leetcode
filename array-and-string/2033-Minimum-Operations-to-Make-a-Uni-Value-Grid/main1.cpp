#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rows = grid.size(), columns = grid[0].size(), gridSize = rows * columns, remainder = grid[0][0] % x;
        vector<int> flattened(gridSize);
        for (int i = 0; i < rows; ++i) { for (int j = 0; j < columns; ++j) { if (grid[i][j] % x != remainder) return -1; flattened[i * columns + j] = grid[i][j]; } }
        sort(flattened.begin(), flattened.end());
        int mid = flattened[gridSize / 2], result = 0;
        for (const int i : flattened) result += abs(i - mid) / x;
        return result;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> grid1 = {
        {2, 4},
        {6, 8}
    };
    cout << s.minOperations(grid1, 2) << endl;
    vector<vector<int>> grid2 = {
        {1, 5},
        {2, 3}
    };
    cout << s.minOperations(grid2, 1) << endl;
    vector<vector<int>> grid3 = {
        {1, 2},
        {3, 4}
    };
    cout << s.minOperations(grid3, 2) << endl;
	return 0;
}
