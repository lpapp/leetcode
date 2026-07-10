#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        const int n = values.size();
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& e : edges) { adj[e[0]].emplace_back(e[1], e[2]); adj[e[1]].emplace_back(e[0], e[2]); }
        vector<bool> visited(n, false); visited[0] = true;
        int res = 0;
        auto dfs = [&](this auto& dfs, int u, int time, int val) -> void {
            if (u == 0) res = max(res, val);
            for (const pair<int, int> next : adj[u]) {
                const int v = next.first, t = next.second;
                if (time + t > maxTime) continue;
                if (visited[v]) dfs(v, time + t, val);
                else { visited[v] = true; dfs(v, time + t, val + values[v]); visited[v] = false; }
            }
        };
        dfs(0, 0, values[0]);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> values1 = {0, 32, 10, 43};
    vector<vector<int>> edges1 = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}};
    assert(s.maximalPathQuality(values1, edges1, 49) == 75);

    vector<int> values2 = {5, 10, 15, 20};
    vector<vector<int>> edges2 = {{0, 1, 10}, {1, 2, 10}, {0, 3, 10}};
    assert(s.maximalPathQuality(values2, edges2, 30) == 25);

    vector<int> values3 = {1, 2, 3, 4};
    vector<vector<int>> edges3 = {{0, 1, 10}, {1, 2, 11}, {2, 3, 12}, {1, 3, 13}};
    assert(s.maximalPathQuality(values3, edges3, 50) == 7);
    return 0;
}
