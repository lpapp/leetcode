#include <array>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    bool dfs(size_t cellIndex, vector<pair<int, int>>& emptyCells, array<array<bool, 9>, 9>& rowUsed, array<array<bool, 9>, 9>& columnUsed, array<array<array<bool, 9>, 3>, 3>& blockUsed, vector<vector<char>>& board, bool& found) {
        if (cellIndex == emptyCells.size()) return true;
        size_t row = emptyCells[cellIndex].first, column = emptyCells[cellIndex].second;
        size_t blockRow = row / 3, blockColumn = column / 3;
        for (size_t index = 0; index < 9; ++index) {
            if (rowUsed[row][index] || columnUsed[column][index] || blockUsed[blockRow][blockColumn][index]) continue;
            rowUsed[row][index] = true;
            columnUsed[column][index] = true;
            blockUsed[blockRow][blockColumn][index] = true;
            board[row][column] = index + '1';
            if (dfs(cellIndex + 1, emptyCells, rowUsed, columnUsed, blockUsed, board, found)) return true;
            rowUsed[row][index] = false;
            columnUsed[column][index] = false;
            blockUsed[blockRow][blockColumn][index] = false;
        }
        return false;
    };
public:
    void solveSudoku(vector<vector<char>>& board) {
        array<array<bool, 9>, 9> rowUsed = {};
        array<array<bool, 9>, 9> columnUsed = {};
        array<array<array<bool, 9>, 3>, 3> blockUsed = {};
        bool found = false;
        vector<pair<int, int>> emptyCells;
        for (size_t row = 0; row < 9; ++row) {
            for (size_t column = 0; column < 9; ++column) {
                if (board[row][column] == '.') emptyCells.push_back({row, column});
                else {
                    const size_t index = board[row][column] - '1';
                    rowUsed[row][index] = true;
                    columnUsed[column][index] = true;
                    blockUsed[row / 3][column / 3][index] = true;
                }
            }
        }
        dfs(0, emptyCells, rowUsed, columnUsed, blockUsed, board, found);
    }
};

void printVectorVector(const vector<vector<char>>& input)
{
    cout << "[";
    for (const vector<char>& v: input) {
        cout << "[";
        for (const char c: v) {
            cout << c << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<vector<char>> board1 = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    s.solveSudoku(board1);
    printVectorVector(board1);
	return 0;
}
