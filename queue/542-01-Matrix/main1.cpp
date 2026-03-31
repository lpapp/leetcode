#include <array>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int rows = mat.size(), columns = mat[0].size();
        vector<vector<int>> result(rows, vector<int>(columns, -1));
        queue<pair<int, int>> q;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (!mat[row][column]) {
                    result[row][column] = 0;
                    q.emplace(row, column);
                }
            }
        }
        array<int, 5> directions = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            const auto [row, column] = q.front(); q.pop();
            for (size_t i = 0; i < 4; ++i) {
                int nextRow = row + directions[i], nextColumn = column + directions[i + 1];
                if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns && result[nextRow][nextColumn] == -1) {
                    result[nextRow][nextColumn] = result[row][column] + 1;
                    q.emplace(nextRow, nextColumn);
                }
            }
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
	vector<vector<int>> mat1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    printVectorVector(s.updateMatrix(mat1));
	vector<vector<int>> mat2 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    printVectorVector(s.updateMatrix(mat2));
    return 0;
}
