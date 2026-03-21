#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int rows = board.size(), columns = board[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                int live = -board[row][column];
                for (int r = row - 1; r <= row + 1; ++r) {
                    for (int c = column - 1; c <= column + 1; ++c) {
                        if (r >= 0 && r < rows && c >= 0 && c < columns && board[r][c] > 0) ++live;
                    }
                }
                if (board[row][column] == 1 && (live < 2 || live > 3)) board[row][column] = 2;
                if (!board[row][column] && live == 3) board[row][column] = -1;
            }
        }
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (board[row][column] == 2) board[row][column] = 0;
                else if (board[row][column] == -1) board[row][column] = 1;
            }
        }
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
    vector<vector<int>> board1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    s.gameOfLife(board1);
    printVectorVector(board1);

    vector<vector<int>> board2 = {
        {1, 1},
        {1, 0}
    };
    s.gameOfLife(board2);
    printVectorVector(board2);
	return 0;
}
