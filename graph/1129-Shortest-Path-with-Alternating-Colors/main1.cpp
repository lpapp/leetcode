#include <array>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> g[2]{vector<vector<int>>(n), vector<vector<int>>(n)};
        for (const vector<int>& e : redEdges) g[0][e[0]].push_back(e[1]);
        for (const vector<int>& e : blueEdges) g[1][e[0]].push_back(e[1]);
        vector<int> res(n, -1);
        vector<array<bool, 2>> vis(n, {false, false});
        vis[0] = {true, true};
        queue<pair<int, int>> q({{0, 0}, {0, 1}});
        for (int d = 0; !q.empty(); ++d)
            for (int i = 0, sz = q.size(); i < sz; ++i) {
                const auto [u, c] = q.front(); q.pop();
                if (res[u] < 0) res[u] = d;
                const int nc = c ^ 1;
                for (const int v : g[nc][u])
                    if (!vis[v][nc]) { vis[v][nc] = true; q.emplace(v, nc); }
            }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> redEdges1 = {{0, 1}, {1, 2}};
    vector<vector<int>> blueEdges1 = {};
    vector<int> res1 = {0, 1, -1};
    assert(s.shortestAlternatingPaths(3, redEdges1, blueEdges1) == res1);

    vector<vector<int>> redEdges2 = {{0, 1}};
    vector<vector<int>> blueEdges2 = {{2, 1}};
    vector<int> res2 = {0, 1, -1};
    assert(s.shortestAlternatingPaths(3, redEdges2, blueEdges2) == res2);
    return 0;
}
