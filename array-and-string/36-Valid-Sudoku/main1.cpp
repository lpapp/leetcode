#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<bool, 9>, 9> rows = {};
        array<array<bool, 9>, 9> columns = {};
        array<array<bool, 9>, 9> subBoard = {};
        for (size_t row = 0; row < 9; ++row) {
            for (size_t column = 0; column < 9; ++column) {
                const char cell = board[row][column];
                if (cell == '.') continue;
                const int digit = cell - '1';
                const int subBoardIndex = (row / 3) * 3 + (column / 3);
                if (rows[row][digit] || columns[column][digit] || subBoard[subBoardIndex][digit]) return false;
                rows[row][digit] = true, columns[column][digit] = true, subBoard[subBoardIndex][digit] = true;
            }
        }
        return true;       
    }
};

int main()
{
	Solution s;
    vector<vector<char>> board1 = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    cout << s.isValidSudoku(board1) << endl;
    vector<vector<char>> board2 = {
        { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' },
    };
    cout << s.isValidSudoku(board2) << endl;
	return 0;
}
