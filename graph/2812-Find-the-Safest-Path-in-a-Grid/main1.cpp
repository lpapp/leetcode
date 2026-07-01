#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
          const int n = grid.size();
          if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
          vector<vector<int>> dist(n, vector<int>(n, -1));
          queue<pair<int,int>> q;
          for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (grid[i][j] == 1) { dist[i][j] = 0; q.push({i, j}); }
          constexpr int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
          while (!q.empty()) {
              auto [x, y] = q.front(); q.pop();
              for (int d = 0; d < 4; ++d) {
                  const int nx = x + dx[d], ny = y + dy[d];
                  if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) { dist[nx][ny] = dist[x][y] + 1; q.push({nx, ny}); }
              }
          }
          const int maxDist = 2 * (n - 1);
          vector<vector<pair<int,int>>> buckets(maxDist + 1);
          vector<vector<int>> safeness(n, vector<int>(n, -1));
          safeness[0][0] = dist[0][0];
          buckets[dist[0][0]].push_back({0, 0});
          for (int b = maxDist; b >= 0; --b) {
              while (!buckets[b].empty()) {
                  auto [x, y] = buckets[b].back(); buckets[b].pop_back();
                  if (x == n-1 && y == n-1) return b;
                  for (int d = 0; d < 4; ++d) {
                      const int nx = x + dx[d], ny = y + dy[d];
                      if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                          const int newSafe = min(b, dist[nx][ny]);
                          if (newSafe > safeness[nx][ny]) { safeness[nx][ny] = newSafe; buckets[newSafe].push_back({nx, ny}); }
                      }
                  }
              }
          }
          return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    assert(!s.maximumSafenessFactor(grid1));
    vector<vector<int>> grid2 = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    assert(s.maximumSafenessFactor(grid2) == 2);
    vector<vector<int>> grid3 = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    assert(s.maximumSafenessFactor(grid3) == 2);
    return 0;
}
