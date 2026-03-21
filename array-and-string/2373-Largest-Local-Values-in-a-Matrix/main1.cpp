#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const size_t n = grid.size();
        vector<vector<int>> result(n - 2, vector<int>(n - 2));
        for (size_t row = 0; row < n - 2; ++row) {
            for (size_t column = 0; column < n - 2; ++column) {
                for (size_t subRow = row; subRow <= row + 2; ++subRow) {
                    for (size_t subColumn = column; subColumn <= column + 2; ++subColumn) result[row][column] = max(result[row][column], grid[subRow][subColumn]);
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
    vector<vector<int>> grid1 = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2}
    };
    printVectorVector(s.largestLocal(grid1));

    vector<vector<int>> grid2 = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    printVectorVector(s.largestLocal(grid2));
	return 0;
}
