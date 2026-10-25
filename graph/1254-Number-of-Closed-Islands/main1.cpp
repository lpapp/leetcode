#include <cassert>
#include <functional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
    static int dfs(vector<vector<int>>& grid, const int rows, const int columns, const int row, const int column) {
        int closed = row > 0 && row < rows - 1 && column > 0 && column < columns - 1;
        grid[row][column] = 1;
        if (row + 1 < rows && !grid[row + 1][column]) closed &= dfs(grid, rows, columns, row + 1, column);
        if (row > 0 && !grid[row - 1][column]) closed &= dfs(grid, rows, columns, row - 1, column);
        if (column + 1 < columns && !grid[row][column + 1]) closed &= dfs(grid, rows, columns, row, column + 1);
        if (column > 0 && !grid[row][column - 1]) closed &= dfs(grid, rows, columns, row, column - 1);
        return closed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size(), res = 0;
        for (int row = 1; row < rows - 1; ++row) for (int column = 1; column < columns - 1; ++column) if (!grid[row][column]) res += dfs(grid, rows, columns, row, column);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };
    assert(s.closedIsland(grid1) == 2);
    vector<vector<int>> grid2 = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}
    };
    assert(s.closedIsland(grid2) == 1);
    vector<vector<int>> grid3 = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };
    assert(s.closedIsland(grid3) == 2);
    return 0;
}
