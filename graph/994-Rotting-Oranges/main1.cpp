#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> rottenQueue;
        int freshCount = 0;
        for (int row = 0; row < rows; ++row) for (int col = 0; col < cols; ++col) {
            if (grid[row][col] == 1) ++freshCount;
            else if (grid[row][col] == 2) rottenQueue.emplace(row, col);
        }
        constexpr int directions[5] = {-1, 0, 1, 0, -1};
        for (int minute = 1; !rottenQueue.empty() && freshCount > 0; ++minute) {
            for (int currentLevelSize = rottenQueue.size(), i = 0; i < currentLevelSize; ++i) {
                const auto [currentRow, currentCol] = rottenQueue.front();
                rottenQueue.pop();
                for (int dir = 0; dir < 4; ++dir) {
                    const int nextRow = currentRow + directions[dir], nextCol = currentCol + directions[dir + 1];
                    if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        rottenQueue.emplace(nextRow, nextCol);
                        if (--freshCount == 0) return minute;
                    }
                }
            }
        }
        return freshCount > 0 ? -1 : 0;       
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    assert(s.orangesRotting(grid1) == 4);
    vector<vector<int>> grid2 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    assert(s.orangesRotting(grid2) == -1);
    vector<vector<int>> grid3 = {
        {0, 2},
    };
    assert(s.orangesRotting(grid3) == 0);
    return 0;
}
