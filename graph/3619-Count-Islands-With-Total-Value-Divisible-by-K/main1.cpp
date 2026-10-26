#include <cassert>
#include <functional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
    static long long dfs(vector<vector<int>>& grid, const int rows, const int columns, const int row, const int column) {
        long long sum = grid[row][column];
        grid[row][column] = 0;
        if (row + 1 < rows && grid[row + 1][column]) sum += dfs(grid, rows, columns, row + 1, column);
        if (row > 0 && grid[row - 1][column]) sum += dfs(grid, rows, columns, row - 1, column);
        if (column + 1 < columns && grid[row][column + 1]) sum += dfs(grid, rows, columns, row, column + 1);
        if (column > 0 && grid[row][column - 1]) sum += dfs(grid, rows, columns, row, column - 1);
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), columns = grid[0].size(), res = 0;
        for (int row = 0; row < rows; ++row) for (int column = 0; column < columns; ++column) if (grid[row][column]) res += dfs(grid, rows, columns, row, column) % k == 0;
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{0, 2, 1, 0, 0}, {0, 5, 0, 0, 5}, {0, 0, 1, 0, 0}, {0, 1, 4, 7, 0}, {0, 2, 0, 0, 8}};
    assert(s.countIslands(grid1, 5) == 2);
    vector<vector<int>> grid2 = {{3, 0, 3, 0}, {0, 3, 0, 3}, {3, 0, 3, 0}};
    assert(s.countIslands(grid2, 3) == 6);
    return 0;
}
