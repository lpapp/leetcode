#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        const int directions[5] = {0, 1, 0, -1, 0};
        int row = 0, column = 0;
        int directionsIndex = 0;
        for (int value = 1; value <= n * n; ++value) {
            result[row][column] = value;
            int nextRow = row + directions[directionsIndex];
            int nextColumn = column + directions[directionsIndex + 1];
            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || result[nextRow][nextColumn]) directionsIndex = (directionsIndex + 1) % 4;
            row += directions[directionsIndex];
            column += directions[directionsIndex + 1];
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
    printVectorVector(s.generateMatrix(3));
    printVectorVector(s.generateMatrix(1));
	return 0;
}
