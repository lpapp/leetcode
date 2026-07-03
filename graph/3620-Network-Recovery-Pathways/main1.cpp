#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    bool check(int n, vector<vector<pair<int, long long>>>& adj, vector<bool>& online, long long k, long long threshold) {
        vector<int> deg(n, 0);
        for (int u = 0; u < n; ++u) {
            if (!online[u] && u != 0 && u != n - 1) continue;
            for (pair<int, long long> edge : adj[u]) if (edge.second >= threshold) ++deg[edge.first];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (deg[i] == 0 && (online[i] || i == 0 || i == n - 1)) q.push(i);
        vector<int> order; order.reserve(n);
        while (!q.empty()) {
            const int u = q.front(); q.pop();
            order.push_back(u);
            if (!online[u] && u != 0 && u != n - 1) continue;
            for (pair<int, long long> edge : adj[u]) {
                if (edge.second < threshold) continue;
                if (--deg[edge.first] == 0) q.push(edge.first);
            }
        }
        constexpr long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        for (int u : order) {
            if (dist[u] == INF) continue;
            if (!online[u] && u != 0 && u != n - 1) continue;
            for (pair<int, long long> edge : adj[u]) {
                if (edge.second < threshold) continue;
                dist[edge.first] = min(dist[edge.first], dist[u] + edge.second);
            }
        }
        return dist[n - 1] <= k;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        const int n = online.size();
        vector<vector<pair<int, long long>>> adj(n);
        vector<long long> costs;
        costs.reserve(edges.size());
        for (vector<int>& edge : edges) {
            const int u = edge[0], v = edge[1];
            const long long c = edge[2];
            if (!online[u] && u != 0 && u != n - 1) continue;
            if (!online[v] && v != 0 && v != n - 1) continue;
            adj[u].emplace_back(v, c);
            costs.push_back(c);
        }
        if (costs.empty()) return -1;
        ranges::sort(costs);
        const auto [first, last] = ranges::unique(costs);
        costs.erase(first, last);
        int res = -1;
        for (int lo = 0, hi = costs.size() - 1; lo <= hi; ) {
            const int mid = lo + (hi - lo) / 2;
            if (check(n, adj, online, k, costs[mid])) { res = costs[mid]; lo = mid + 1; }
            else hi = mid - 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
    vector<bool> online1 = {true, true, true, true};
    assert(s.findMaxPathScore(edges1, online1, 10) == 3);
    vector<vector<int>> edges2 = {{0, 1, 7}, {1, 4, 5}, {0, 2, 6}, {2, 3, 6}, {3, 4, 2}, {2, 4, 6}};
    vector<bool> online2 = {true, true, true, false, true};
    assert(s.findMaxPathScore(edges2, online2, 12) == 6);
    return 0;
}
