#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	void placeQueens(size_t gridSize, size_t row, vector<bool>& columnCellsPlaced, vector<bool>& diagonalCellsPlaced, vector<bool>& inverseDiagonalCellsPlaced, int& result) {
		if (row == gridSize) { ++result; return; }

        for (size_t column = 0; column < gridSize; ++column) {
            if (columnCellsPlaced[column]
				|| diagonalCellsPlaced[row + column] 
                || inverseDiagonalCellsPlaced[gridSize - row + column]) continue;

            columnCellsPlaced[column]
				= diagonalCellsPlaced[row + column]
                = inverseDiagonalCellsPlaced[gridSize - row + column]
				= true;

            placeQueens(gridSize, row + 1, columnCellsPlaced, diagonalCellsPlaced, inverseDiagonalCellsPlaced, result);

            columnCellsPlaced[column]
				= diagonalCellsPlaced[row + column]
                = inverseDiagonalCellsPlaced[gridSize - row + column]
				= false;
        }
    };
public:
    int totalNQueens(int n) {
        vector<bool> columnCellsPlaced(n, 0);
        vector<bool> diagonalCellsPlaced(2 * n, 0);
        vector<bool> inverseDiagonalCellsPlaced(2 * n, 0);

        int result = 0;
        placeQueens(n, 0, columnCellsPlaced, diagonalCellsPlaced, inverseDiagonalCellsPlaced, result);
        return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.totalNQueens(4) << endl;
	cout << solution.totalNQueens(1) << endl;
	return 0;
}
