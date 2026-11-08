#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size(), res = 0;
        vector<int> rowCount(rows), lastColumn(rows), columnCount(columns);
        for (int row = 0; row < rows; ++row) for (int column = 0; column < columns; ++column) if (grid[row][column]) { ++rowCount[row]; ++columnCount[column]; lastColumn[row] = column; }
        for (int row = 0; row < rows; ++row) res += rowCount[row] > 1 ? rowCount[row] : rowCount[row] == 1 && columnCount[lastColumn[row]] > 1;
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    assert(s.countServers(grid1) == 0);
    vector<vector<int>> grid2 = {{1, 0}, {1, 1}};
    assert(s.countServers(grid2) == 3);
    vector<vector<int>> grid3 = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    assert(s.countServers(grid3) == 4);
    return 0;
}
