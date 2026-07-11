#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0, m = grid.size(); i < m; ++i) for (int j = 0, n = grid[0].size(); j < n; ++j) if (grid[i][j]) { res += 4; if (i + 1 < m && grid[i + 1][j]) res -= 2; if (j + 1 < n && grid[i][j + 1]) res -= 2; }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    assert(s.islandPerimeter(grid1) == 16);
    vector<vector<int>> grid2 = {{1}};
    assert(s.islandPerimeter(grid2) == 4);
    vector<vector<int>> grid3 = {{1, 0}};
    assert(s.islandPerimeter(grid3) == 4);
    return 0;
}
