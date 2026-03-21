#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const size_t rows = grid.size(), columns = grid[0].size();
        vector<vector<int>> result(rows, vector<int>(columns));
        for (size_t row = 0; row < rows; ++row) {
            for (size_t column = 0; column < columns; ++column) {
                const size_t originalIndex = row * columns + column;
                const size_t shiftedIndex = (originalIndex + k) % (rows * columns);
                const size_t shiftedRow = shiftedIndex / columns, shiftedColumn = shiftedIndex % columns;
                result[shiftedRow][shiftedColumn] = grid[row][column];
            }
        }
        return result;
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int& i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<vector<int>> grid1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printVectorVector(s.shiftGrid(grid1, 1));

    vector<vector<int>> grid2 = {
        {3, 8, 1, 9},
        {19, 7, 2, 5},
        {4, 6, 11, 10},
        {12, 0, 21, 13}
    };
    printVectorVector(s.shiftGrid(grid2, 4));

    vector<vector<int>> grid3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printVectorVector(s.shiftGrid(grid3, 9));
	return 0;
}
