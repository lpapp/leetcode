#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for (const vector<int>& edge: edges) adj[edge[0]].push_back(edge[1]);
        vector<long long> res(n);
        vector<int> order;
        for (vector<int> s{0}; !s.empty();) { int u = s.back(); s.pop_back(); order.push_back(u); for (const int v : adj[u]) s.push_back(v); }
        reverse(order.begin(), order.end());
        for (const int u : order) {
            if (adj[u].empty()) res[u] = baseTime[u];
            else { long long earliest = LLONG_MAX, latest = LLONG_MIN; for (const int v : adj[u]) { earliest = min(earliest, res[v]); latest = max(latest, res[v]); } res[u] = latest + latest - earliest + baseTime[u]; }
        }
        return res[0];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
    vector<int> baseTime1 = {9, 5, 3};
    assert(s.finishTime(3, edges1, baseTime1) == 17);
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}};
    vector<int> baseTime2 = {4, 7, 6};
    assert(s.finishTime(3, edges2, baseTime2) == 12);
    vector<vector<int>> edges3 = {{0, 1}, {0, 2}, {2, 3}};
    vector<int> baseTime3 = {5, 8, 2, 1};
    assert(s.finishTime(4, edges3, baseTime3) == 18);
    return 0;
}
