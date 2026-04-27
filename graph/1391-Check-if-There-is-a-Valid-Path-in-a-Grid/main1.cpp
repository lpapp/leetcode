#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<size_t> parent;
    int findParent(size_t x) {
        if (parent[x] != x) parent[x] = findParent(parent[x]);
        return parent[x];
    }
    void connectLeft(size_t row, size_t column, size_t columns, vector<vector<int>>& grid) {
        if (column > 0 && (grid[row][column - 1] == 1 || grid[row][column - 1] == 4 || grid[row][column - 1] == 6)) parent[findParent(row * columns + column)] = findParent(row * columns + column - 1);
    }
    void connectRight(size_t row, size_t column, size_t columns, vector<vector<int>>& grid) {
        if (column < columns - 1 && (grid[row][column + 1] == 1 || grid[row][column + 1] == 3 || grid[row][column + 1] == 5)) parent[findParent(row * columns + column)] = findParent(row * columns + column + 1);
    };
    void connectUp(size_t row, size_t column, size_t columns, vector<vector<int>>& grid) {
        if (row > 0 && (grid[row - 1][column] == 2 || grid[row - 1][column] == 3 || grid[row - 1][column] == 4)) parent[findParent(row * columns + column)] = findParent((row - 1) * columns + column);
    }
    void connectDown(size_t row, size_t column, size_t rows, size_t columns, vector<vector<int>>& grid) {
        if (row < rows - 1 && (grid[row + 1][column] == 2 || grid[row + 1][column] == 5 || grid[row + 1][column] == 6)) parent[findParent(row * columns + column)] = findParent((row + 1) * columns + column);
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        const size_t rows = grid.size(), columns = grid[0].size();
        parent.resize(rows * columns);
        for (size_t i = 0; i < parent.size(); ++i) parent[i] = i;
        for (size_t row = 0; row < rows; ++row) {
            for (size_t column = 0; column < columns; ++column) {
                const int streetType = grid[row][column];
                if (streetType == 1) { connectLeft(row, column, columns, grid); connectRight(row, column, columns, grid); }
                else if (streetType == 2) { connectUp(row, column, columns, grid); connectDown(row, column, rows, columns, grid); }
                else if (streetType == 3) { connectLeft(row, column, columns, grid); connectDown(row, column, rows, columns, grid); }
                else if (streetType == 4) { connectRight(row, column, columns, grid); connectDown(row, column, rows, columns, grid); }
                else if (streetType == 5) { connectLeft(row, column, columns, grid); connectUp(row, column, columns, grid); }
                else { connectRight(row, column, columns, grid); connectUp(row, column, columns, grid); }
            }
        }
        return findParent(0) == findParent(rows * columns - 1);
    }
};

int main()
{
	Solution s;
    vector<vector<int>> grid1 = {
        {2, 4, 3},
        {6, 5, 2}
    };
    cout << s.hasValidPath(grid1) << endl;
    vector<vector<int>> grid2 = {
        {1, 2, 1},
        {1, 2, 1}
    };
    cout << s.hasValidPath(grid2) << endl;
    vector<vector<int>> grid3 = {
        {1, 1, 2},
    };
    cout << s.hasValidPath(grid3) << endl;
	return 0;
}
