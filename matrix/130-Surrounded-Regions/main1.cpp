#include <array>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    void dfs(int row, int column, int rows, int columns, vector<vector<char>>& board, const array<int, 5>& directions) {
        if (row < 0 || row >= rows || column < 0 || column >= columns || board[row][column] != 'O') return;
        board[row][column] = '.';
        for (int k = 0; k < 4; ++k) dfs(row + directions[k], column + directions[k + 1], rows, columns, board, directions);
    };
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), columns = board[0].size();
        constexpr array<int, 5> directions = {-1, 0, 1, 0, -1};
        for (int i = 0; i < rows; ++i) { dfs(i, 0, rows, columns, board, directions); dfs(i, columns - 1, rows, columns, board, directions); }
        for (int j = 1; j < columns - 1; ++j) { dfs(0, j, rows, columns, board, directions); dfs(rows - 1, j, rows, columns, board, directions); }
        for (vector<char>& row : board) {
            for (char& cell : row) {
                if (cell == '.') cell = 'O';
                else if (cell == 'O') cell = 'X';
            }
        }
    }
};

int main()
{
	Solution s;
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    vector<vector<char>> res1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}
    }; 
    s.solve(board1);
    assert(board1 == res1);
    vector<vector<char>> board2 = {{'X'}};
    vector<vector<char>> res2 = {{'X'}}; 
    s.solve(board2);
    assert(board2 == res2);
	return 0;
}
