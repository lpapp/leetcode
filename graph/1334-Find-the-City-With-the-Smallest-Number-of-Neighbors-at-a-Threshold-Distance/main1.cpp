#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        constexpr int INF = 1'000'000'000;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) dist[i][i] = 0;
        for (const vector<int>& edge : edges) { dist[edge[0]][edge[1]] = edge[2]; dist[edge[1]][edge[0]] = edge[2]; }
        for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int res = 0, minCount = n;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) count += (i != j && dist[i][j] <= distanceThreshold);
            if (count <= minCount) { minCount = count; res = i; }
        }
        return res;       
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    assert(s.findTheCity(4, edges1, 4) == 3);
    vector<vector<int>> edges2 = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    assert(!s.findTheCity(5, edges2, 2));
    return 0;
}
