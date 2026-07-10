#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        vector<vector<int>> adj(n);
        for (vector<int>& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        vector<bool> visited(n, false); visited[source] = true;
        const auto dfs = [&](this auto& dfs, int u) -> bool {
            if (u == destination) return true;
            for (const int v : adj[u]) { if (visited[v]) continue; visited[v] = true; if (dfs(v)) return true; }
            return false;
        };
        return dfs(source);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    assert(s.validPath(3, edges1, 0, 2));
    vector<vector<int>> edges2 = {{0 ,1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    assert(!s.validPath(6, edges2, 0, 5));
    return 0;
}
