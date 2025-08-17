#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    array<int, 5> directions = {-1, 0, 1, 0, -1};
	int dfs(vector<vector<int>>& grid, size_t zeroCount, int row, int column, size_t pathCount, int rows, int columns, vector<vector<bool>>& visited) {
	    if (grid[row][column] == 2) return pathCount == zeroCount + 1 ? 1 : 0;
	
	    int pathCountTotal = 0;
	    for (size_t i = 0; i < 4; ++i) {
	        int nextRow = row + directions[i], nextColumn = column + directions[i + 1];
	        if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns
	            && !visited[nextRow][nextColumn] && grid[nextRow][nextColumn] != -1) {
	            visited[nextRow][nextColumn] = true;
	            pathCountTotal += dfs(grid, zeroCount, nextRow, nextColumn, pathCount + 1, rows, columns, visited);
	            visited[nextRow][nextColumn] = false;
	        }
	    }
	
	    return pathCountTotal;
	};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        const size_t rows = grid.size();
        const size_t columns = grid[0].size();
        size_t zeroCount = 0;
        for (const vector<int>& row : grid) {
            for (const int cell : row) zeroCount += !cell;
        }

        vector<vector<bool>> visited(rows, vector<bool>(columns, false));

        for (size_t row = 0; row < rows; ++row) {
            for (size_t column = 0; column < columns; ++column) {
                if (grid[row][column] == 1) {
                    visited[row][column] = true;
                    return dfs(grid, zeroCount, row, column, 0, rows, columns, visited);
                }
            }
        }

        return 0;
    }
};

int main()
{
	Solution solution;
	vector<vector<int>> input1 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
	cout << solution.uniquePathsIII(input1) << endl;

    vector<vector<int>> input2 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
	cout << solution.uniquePathsIII(input2) << endl;

    vector<vector<int>> input3 = {{0, 1}, {2, 0}};
	cout << solution.uniquePathsIII(input3) << endl;

	return 0;
}
