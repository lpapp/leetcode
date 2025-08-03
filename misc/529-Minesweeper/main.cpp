#include <vector>

using namespace std;

class Solution {
	void dfs(int row, int col, int rows, int cols, vector<vector<char>>& board) {
	    size_t mineCount = 0;
	
	    // Count mines in adjacent cells
	    for (int r = row - 1; r <= row + 1; ++r) {
	        for (int c = col - 1; c <= col + 1; ++c) {
	            if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == 'M') {
	                ++mineCount;
	            }
	        }
	    }
	
		// If mines exist around the cell, update the cell with the mine
		// count. Otherwise, mark the cell as 'B' and continue DFS.
	    if (mineCount > 0) {
	        board[row][col] = mineCount + '0';
	    } else {
	        board[row][col] = 'B';
	        for (int r = row - 1; r <= row + 1; ++r) {
	            for (int c = col - 1; c <= col + 1; ++c) {
	                if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == 'E') {
	                    dfs(r, c, rows, cols, board);
	                }
	            }
	        }
	    }
	};

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        size_t rows = board.size(), cols = board[0].size();
        size_t clickRow = click[0], clickCol = click[1];

        // If the clicked cell contains a mine, game over
        if (board[clickRow][clickCol] == 'M') board[clickRow][clickCol] = 'X';
        // If the clicked cell is empty ('E'), perform DFS to reveal cells
        else dfs(clickRow, clickCol, rows, cols, board);

        return board;
    }
};

int main()
{
	Solution solution;
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click = {3, 0};
    solution.updateBoard(board, click);
	return 0;
}
