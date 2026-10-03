#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, yz = 0, zx = 0;
        for (int i = 0, n = grid.size(); i < n; ++i) {
            int rowMax = 0, colMax = 0;
            for (int j = 0; j < n; ++j) {
                xy += grid[i][j] > 0;
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            yz += rowMax;
            zx += colMax;
        }
        return xy + yz + zx;       
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {
        {1, 2},
        {3, 4}
    };
    assert(s.projectionArea(grid1) == 17);
    vector<vector<int>> grid2 = {
        {2},
    };
    assert(s.projectionArea(grid2) == 5);
    vector<vector<int>> grid3 = {
        {1, 0},
        {0, 2}
    };
    assert(s.projectionArea(grid3) == 8);
    return 0;
}
