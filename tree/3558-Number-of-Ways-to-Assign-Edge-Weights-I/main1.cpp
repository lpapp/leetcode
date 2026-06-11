#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
          const int n = edges.size() + 1;
          constexpr int MOD = 1e9 + 7;
          vector<vector<int>> adj(n + 1);
          for (const vector<int>& edge : edges) {
              adj[edge[0]].push_back(edge[1]);
              adj[edge[1]].push_back(edge[0]);
          }
          vector<int> depth(n + 1, -1); depth[1] = 0;
          int maxDepth = 0;
          for (queue<int> q({1}); !q.empty(); ) {
              const int u = q.front(); q.pop();
              for (const int v : adj[u]) {
                  if (depth[v] == -1) {
                      depth[v] = depth[u] + 1;
                      maxDepth = max(maxDepth, depth[v]);
                      q.push(v);
                  }
              }
          }
          long long res = 1, base = 2;
          for (int exp = maxDepth - 1; exp > 0; exp >>= 1) {
              if (exp & 1) res = res * base % MOD;
              base = base * base % MOD;
          }
          return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{1, 2}};
    assert(s.assignEdgeWeights(edges1) == 1);
    vector<vector<int>> edges2 = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    assert(s.assignEdgeWeights(edges2) == 2);
    return 0;
}
