#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(int row, int column, int rows, int columns, vector<vector<char>>& grid, array<int, 5>& directions) {
            grid[row][column] = '0';
            for (size_t k = 0; k < 4; ++k) {
                int nextRow = row + directions[k], nextColumn = column + directions[k + 1];
                if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns && grid[nextRow][nextColumn] == '1') dfs(nextRow, nextColumn, rows, columns, grid, directions);
            }
        };
public:
    int numIslands(vector<vector<char>>& grid) {
        const size_t rows = grid.size(), columns = grid[0].size();
        int result = 0;
        array<int, 5> directions = {-1, 0, 1, 0, -1};
        for (size_t i = 0; i < rows; ++i) for (size_t j = 0; j < columns; ++j) if (grid[i][j] == '1') { dfs(i, j, rows, columns, grid, directions); ++result; }
        return result;
    }
};

int main()
{
	Solution s;
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << s.numIslands(grid1) << endl;
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << s.numIslands(grid2) << endl;
	return 0;
}
