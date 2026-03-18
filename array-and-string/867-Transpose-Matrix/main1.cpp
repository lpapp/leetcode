#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const size_t rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> result(columns, vector<int>(rows));
        for (size_t row = 0; row < columns; ++row) {
            for (size_t column = 0; column < rows; ++column) result[row][column] = matrix[column][row];
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
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printVectorVector(s.transpose(matrix1));
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}};
    printVectorVector(s.transpose(matrix2));
	return 0;
}
