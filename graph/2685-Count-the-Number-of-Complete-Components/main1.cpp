#include <cassert>
#include <vector>

using namespace std;

class Solution {
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int& vertices, int& degrees) {
        vis[u] = true;
        ++vertices;
        degrees += adj[u].size();
        for (const int v : adj[u]) if (!vis[v]) dfs(v, adj, vis, vertices, degrees);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) { adj[edge[0]].push_back(edge[1]); adj[edge[1]].push_back(edge[0]); }
        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int vertices = 0, degrees = 0;
            dfs(i, adj, vis, vertices, degrees);
            res += vertices * (vertices - 1) == degrees;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    assert(s.countCompleteComponents(6, edges1) == 3);

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    assert(s.countCompleteComponents(6, edges2) == 1);
    return 0;
}
