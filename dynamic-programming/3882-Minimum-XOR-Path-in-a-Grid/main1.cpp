#include <bitset>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int rows = grid.size(), columns = grid[0].size();
        vector<bitset<1024>> reachable(columns);
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                bitset<1024> from;
                if (!row && !column) from[0] = 1;
                else {
                    if (row) from |= reachable[column];
                    if (column) from |= reachable[column - 1];
                }
                reachable[column].reset();
                for (int xorValue = 0; xorValue < 1024; ++xorValue) if (from[xorValue]) reachable[column][xorValue ^ grid[row][column]] = 1;
            }
        }
        for (int xorValue = 0; xorValue < 1024; ++xorValue) if (reachable[columns - 1][xorValue]) return xorValue;
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{1, 2}, {3, 4}};
    assert(s.minCost(grid1) == 6);
    vector<vector<int>> grid2 = {{6, 7}, {5, 8}};
    assert(s.minCost(grid2) == 9);
    vector<vector<int>> grid3 = {{2, 7, 5}};
    assert(s.minCost(grid3) == 0);
    return 0;
}
