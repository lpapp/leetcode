#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void placeQueens(int gridSize, int row, vector<int>& columns, vector<vector<string>& results) {
        if (row == gridSize) {
            vector<int> columnsCopy = columns;
            results.push_back(columnsCopy);
        }
        else {
            for (int column = 0; column < gridSize; ++column) {
                if (checkValid(columns, row, column) {
                    columns[row] = column;
                    placeQueens(row + 1, columns, results);
                }
            }
        }
    }

    // Check if (row1, column1) is a valid spot for a queen by checking if
    // there is a queen in the same column or diagonal. We do not need to check
    // it for queens in the same row because the calling placeQueen only
    // attempts to place one queen at a time. We know this row is empty.
    bool checkValid(vector<int>& columns, int row, int column) {
        for (int currentRow = 0; currentRow < row; ++currentRow) {
            int currentColumn = columns[currentRow];
            // Check if (currentRow, currentColumn) invalidates (row, column)
            // as a queen spot.
            
            // Check if rows have a queen in the same column.
            if (column == currentColumn) return false;

            // Check diagonals: if the distance between the columns equals the
            // distance between the rows, then they are then they are in the
            // same diagonal.
            int columnDistance = abs(currentColumn - column);

            // row > currentRow, so no need for abs.
            int rowDistance = row - currentRow;
            if (columnDistance == rowDistance) return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        
    }
};

void printSolution(vector<vector<int>> input)
{
    cout << "[";
    for (const vector<int>& vectorItem : input) {
        cout << "[";
        for (const int item : vectorItem) cout << item << ", ";
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

int main()
{
	Solution solution;
	printSolution(solution.solveNQueens());
	return 0;
}
