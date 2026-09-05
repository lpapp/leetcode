#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        dist[0] = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
            vis[u] = true;
            res += dist[u];
            for (int j = 0; j < n; ++j) if (!vis[j]) dist[j] = min(dist[j], abs(points[u][0] - points[j][0]) + abs(points[u][1] - points[j][1]));
        }
        return res;   
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    assert(s.minCostConnectPoints(points1) == 20);
    vector<vector<int>> points2 = {{3, 12}, {-2, 5}, {-4, 1}};
    assert(s.minCostConnectPoints(points2) == 18);
    return 0;
}
