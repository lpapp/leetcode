#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
public:
    int uniquePaths(vector<vector<int>>& grid) {
        vector<int> down(grid[0].size()), nextDown(grid[0].size()); down[0] = 1;
        for (int row = 0, rows = grid.size(), columns = grid[0].size(); row < rows; ++row) {
            for (int column = 0, right = 0; column < columns; ++column) {
                const int total = (right + down[column]) % MOD;
                if (row == rows - 1 && column == columns - 1) return total;
                nextDown[column] = grid[row][column] ? right : total;
                right = grid[row][column] ? down[column] : total;
            }
            swap(down, nextDown);
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    assert(s.uniquePaths(grid1) == 5);
    vector<vector<int>> grid2 = {
        {0, 0},
        {0, 0}
    };
    assert(s.uniquePaths(grid2) == 2);
    vector<vector<int>> grid3 = {
        {0, 1, 1},
        {1, 1, 0}
    };
    assert(s.uniquePaths(grid3) == 1);
    return 0;
}
