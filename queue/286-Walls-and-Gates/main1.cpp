#include <array>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int rows = rooms.size(), columns = rooms[0].size();
        queue<pair<int, int>> q;
        for (int row = 0; row < rows; ++row) for (int column = 0; column < columns; ++column) if (!rooms[row][column]) q.emplace(row, column);
        int distance = 0;
        array<int, 5> directions = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            ++distance;

            const size_t levelSize = q.size();
            for (size_t i = 0; i < levelSize; ++i) {
                const pair<int, int> cell = q.front(); q.pop();
                for (size_t dir = 0; dir < 4; ++dir) {
                    int row = cell.first + directions[dir];
                    int column = cell.second + directions[dir + 1];
                    if (row >= 0 && row < rows && column >= 0 && column < columns && rooms[row][column] == numeric_limits<int>::max()) {
                        rooms[row][column] = distance;
                        q.emplace(row, column);
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
    vector<vector<int>> rooms1 {
        {numeric_limits<int>::max(), -1, 0, numeric_limits<int>::max()},
        {numeric_limits<int>::max(), numeric_limits<int>::max(), numeric_limits<int>::max(), -1},
        {numeric_limits<int>::max(), -1, numeric_limits<int>::max(), -1},
        {0, -1, numeric_limits<int>::max(), numeric_limits<int>::max()}
    };
    s.wallsAndGates(rooms1);
    printVectorVector(rooms1);
    return 0;
}
