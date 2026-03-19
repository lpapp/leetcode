#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int numberOfCells = rows * cols;
        vector<vector<int>> result = {{rStart, cStart}};
        if (numberOfCells == 1) return result;
        for (int steps = 1;; steps += 2) {
            vector<vector<int>> directions = {
                {0, 1, steps},
                {1, 0, steps},
                {0, -1, steps + 1},
                {-1, 0, steps + 1}
            };
          
            for (const vector<int>& direction : directions) {
                int rowChange = direction[0], columnChange = direction[1], currentSteps = direction[2];
                while (currentSteps-- > 0) {
                    rStart += rowChange, cStart += columnChange;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                        if (static_cast<int>(result.size()) == numberOfCells) return result;
                    }
                }
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
    printVectorVector(s.spiralMatrixIII(1, 4, 0, 0));
    printVectorVector(s.spiralMatrixIII(5, 6, 1, 4));
	return 0;
}
