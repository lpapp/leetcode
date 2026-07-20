#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        constexpr long long INF = LLONG_MAX;
        vector<vector<pair<int, long long>>> fwd(n), rev(n);
        for (vector<int>& e : edges) { fwd[e[0]].emplace_back(e[1], e[2]); rev[e[1]].emplace_back(e[0], e[2]); }
        auto dijkstra = [&](vector<vector<pair<int, long long>>>& g, int src) {
            vector<long long> dist(n, INF);
            dist[src] = 0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; pq.emplace(0LL, src);
            while (!pq.empty()) {
                const auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (const auto [v, w] : g[u]) if (dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.emplace(dist[v], v); }
            }
            return dist;
        };
        const vector<long long> d1 = dijkstra(fwd, src1), d2 = dijkstra(fwd, src2), d3 = dijkstra(rev, dest);
        long long res = INF;
        for (int i = 0; i < n; ++i) {
            if (d1[i] == INF || d2[i] == INF || d3[i] == INF) continue;
            res = min(res, d1[i] + d2[i] + d3[i]);
        }
        return res == INF ? -1 : res;   
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 2, 2}, {0, 5, 6}, {1, 0, 3}, {1, 4, 5}, {2, 1, 1}, {2, 3, 3}, {2, 3, 4}, {3, 4, 2}, {4, 5, 1}}; 
    assert(s.minimumWeight(6, edges1, 0, 1, 5) == 9);

    vector<vector<int>> edges2 = {{0, 1, 1}, {2, 1, 1}};
    assert(s.minimumWeight(3, edges2, 0, 1, 2) == -1);
    return 0;
}
