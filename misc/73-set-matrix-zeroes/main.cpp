#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowHasZero = false;
        bool colHasZero = false;
        
        // Check if the first row contains zero
        for (size_t column = 0; column < matrix[0].size(); ++column) {
            if (!matrix[0][column]) {
                rowHasZero = true;
                break;
            }
        }

        // Check if the first column contains zero
        for (size_t row = 0; row < matrix.size(); ++row) {
            if (!matrix[row][0]) {
                colHasZero = true;
                break;
            }
        }

        // Check for zeros in the rest of the matrix
        for (size_t row = 1; row < matrix.size(); ++row) {
            for (size_t column = 1; column < matrix[0].size(); ++column) {
                if (!matrix[row][column]) {
                    matrix[row][0] = 0;
                    matrix[0][column] = 0;
                }
            }
        }

        // Nullify rows based on values in the first column
        for (size_t row = 1; row < matrix.size(); ++row) {
            if (!matrix[row][0]) nullifyRow(matrix, row);
        }

        // Nullify columns based on values in the first row
        for (size_t column = 1; column < matrix[0].size(); ++column) {
            if (!matrix[0][column]) nullifyColumn(matrix, column);
        }

        // Nullify the first row
        if (rowHasZero) nullifyRow(matrix, 0);

        // Nullify the first column
        if (colHasZero) nullifyColumn(matrix, 0);
    }

    void nullifyRow(vector<vector<int>>& matrix, size_t row) {
        for (size_t column = 0; column < matrix[0].size(); ++column) matrix[row][column] = 0;
    }

    void nullifyColumn(vector<vector<int>>& matrix, size_t column) {
        for (size_t row = 0; row < matrix.size(); ++row) matrix[row][column] = 0;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix1{{1,1,1},{1,0,1},{1,1,1}};
    solution.setZeroes(matrix1);
    vector<vector<int>> matrix2{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    solution.setZeroes(matrix2);
    return 0;
}
