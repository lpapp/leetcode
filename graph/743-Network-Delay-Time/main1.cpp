#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& e : times) adj[e[0] - 1].emplace_back(e[1] - 1, e[2]);
        vector<int> dist(n, INT_MAX); dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k - 1);
        while (!pq.empty()) {
            const auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (const auto [v, w] : adj[u]) if (dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.emplace(dist[v], v); }
        }
        const int res = ranges::max(dist);
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    assert(s.networkDelayTime(times1, 4, 2) == 2);
    vector<vector<int>> times2 = {{1, 2, 1}};
    assert(s.networkDelayTime(times2, 2, 1) == 1);
    vector<vector<int>> times3 = {{1, 2, 1}};
    assert(s.networkDelayTime(times3, 2, 2) == -1);
    return 0;
}
