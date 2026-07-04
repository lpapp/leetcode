#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (const vector<int>& road : roads) { adj[road[0]].emplace_back(road[1], road[2]); adj[road[1]].emplace_back(road[0], road[2]); }
        int res = INT_MAX;
        vector<bool> visited(n + 1, false); visited[1] = true;
        for (queue<int> q({1}); !q.empty();) {
            const int u = q.front(); q.pop();
            for (auto [v, w] : adj[u]) {
                res = min(res, w);
                if (!visited[v]) { visited[v] = true; q.push(v); }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> roads1 = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    assert(s.minScore(4, roads1) == 5);
    vector<vector<int>> roads2 = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
    assert(s.minScore(4, roads2) == 2);
    return 0;
}
