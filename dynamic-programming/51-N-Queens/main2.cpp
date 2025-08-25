#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	void placeQueens(size_t gridSize, size_t row, vector<size_t>& columnCellsPlaced, vector<size_t>& diagonalCellsPlaced, vector<size_t>& inverseDiagonalCellsPlaced, vector<string>& board, vector<vector<string>>& results) {
		if (row == gridSize) { results.push_back(board); return; }

        for (size_t column = 0; column < gridSize; ++column) {
            if (!columnCellsPlaced[column]
				&& !diagonalCellsPlaced[row + column] 
                && !inverseDiagonalCellsPlaced[gridSize - row + column]) {

                board[row][column] = 'Q';
                columnCellsPlaced[column]
					= diagonalCellsPlaced[row + column]
                    = inverseDiagonalCellsPlaced[gridSize - row + column]
					= 1;

                placeQueens(gridSize, row + 1, columnCellsPlaced, diagonalCellsPlaced, inverseDiagonalCellsPlaced, board, results);

                columnCellsPlaced[column]
					= diagonalCellsPlaced[row + column]
                    = inverseDiagonalCellsPlaced[gridSize - row + column]
					= 0;
                board[row][column] = '.';
            }
        }
    };
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<size_t> columnCellsPlaced(n, 0);
        vector<size_t> diagonalCellsPlaced(2 * n, 0);
        vector<size_t> inverseDiagonalCellsPlaced(2 * n, 0);

        vector<vector<string>> results;
        vector<std::string> board(n, string(n, '.'));
        placeQueens(n, 0, columnCellsPlaced, diagonalCellsPlaced, inverseDiagonalCellsPlaced, board, results);
        return results;
    }
};

void printSolution(vector<vector<string>> input)
{
    cout << "[";
    for (const vector<string>& vectorItem : input) {
        cout << "[";
        for (const string& item : vectorItem) cout << item << ", ";
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

int main()
{
	Solution solution;
	printSolution(solution.solveNQueens(4));
	printSolution(solution.solveNQueens(1));
	return 0;
}
