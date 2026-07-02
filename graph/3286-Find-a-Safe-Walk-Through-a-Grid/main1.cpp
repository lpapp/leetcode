#include <cassert>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int m = grid.size(), n = grid[0].size();
        constexpr int dirs[] = {0, 1, 0, -1, 0};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        for (deque<pair<int, int>> dq{{0, 0}}; !dq.empty(); ) {
            auto [r, c] = dq.front(); dq.pop_front();
            for (int d = 0; d < 4; ++d) {
                const int nr = r + dirs[d], nc = c + dirs[d + 1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                const int cost = dist[r][c] + grid[nr][nc];
                if (cost < dist[nr][nc]) {
                    dist[nr][nc] = cost;
                    if (grid[nr][nc] == 0) dq.emplace_front(nr, nc);
                    else dq.emplace_back(nr, nc);
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
    assert(s.findSafeWalk(grid1, 1));
    vector<vector<int>> grid2 = {{0, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}};
    assert(!s.findSafeWalk(grid2, 3));
    vector<vector<int>> grid3 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    assert(s.findSafeWalk(grid3, 5));
    return 0;
}
