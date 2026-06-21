#include <cassert>
#include <functional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& edge : edges) adj[edge[0]].emplace_back(edge[1], edge[2]);
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        while (!pq.empty()) {
            auto [w, u, c] = pq.top(); pq.pop();
            if (u == n - 1) return w;
            if (w > dist[u][c]) continue;
            for (auto [v, wt] : adj[u]) {
                int nc = (labels[v] == labels[u]) ? c + 1 : 1;
                if (nc > k) continue;
                int nw = w + wt;
                if (nw < dist[v][nc]) {
                    dist[v][nc] = nw;
                    pq.push({nw, v, nc});
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0,1, 1}, {1, 2, 1}, {0, 2, 3}};
    assert(s.shortestPath(3, edges1, "aab", 1) == 3);
    vector<vector<int>> edges2 = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
    assert(s.shortestPath(3, edges2, "aab", 2) == 2);
    vector<vector<int>> edges3 = {{0, 1, 1}, {1, 2, 1}};
    assert(s.shortestPath(3, edges3, "aaa", 2) == -1);
    return 0;
}
