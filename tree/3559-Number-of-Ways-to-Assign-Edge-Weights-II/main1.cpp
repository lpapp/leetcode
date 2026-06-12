#include <algorithm>
#include <bit>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
      static constexpr int MOD = 1'000'000'007;
      static long long power(long long base, int exp, int mod) {
          long long res = 1;
          for (base %= mod; exp > 0; base = base * base % mod, exp >>= 1) {
              if (exp & 1) res = res * base % mod;
          }
          return res;
      }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
          const int nodes = edges.size() + 1;
          vector<vector<int>> adj(nodes + 1);
          for (const auto& edge : edges) {
              adj[edge[0]].push_back(edge[1]);
              adj[edge[1]].push_back(edge[0]);
          }
          const int LOG = bit_width((unsigned)nodes);
          vector<int> depth(nodes + 1, 0);
          vector<vector<int>> up(LOG, vector<int>(nodes + 1, 0));
          vector<bool> visited(nodes + 1, false); visited[1] = true;
          for (queue<int> q({1}); !q.empty(); ) {
              const int node = q.front(); q.pop();
              for (const int next : adj[node]) {
                  if (!visited[next]) {
                      visited[next] = true;
                      depth[next] = depth[node] + 1;
                      up[0][next] = node;
                      q.push(next);
                  }
              }
          }
          for (int k = 1; k < LOG; ++k)
              for (int v = 1; v <= nodes; ++v)
                  up[k][v] = up[k - 1][up[k - 1][v]];
          auto lca = [&](int u, int v) {
              if (depth[u] < depth[v]) swap(u, v);
              int diff = depth[u] - depth[v];
              for (int k = 0; k < LOG; ++k)
                  if ((diff >> k) & 1) u = up[k][u];
              if (u == v) return u;
              for (int k = LOG - 1; k >= 0; --k)
                  if (up[k][u] != up[k][v]) { u = up[k][u]; v = up[k][v]; }
              return up[0][u];
          };
          vector<int> res;
          res.reserve(queries.size());
          for (const auto& query : queries) {
              const int dist = depth[query[0]] + depth[query[1]] - 2 * depth[lca(query[0],
  query[1])];
              res.push_back(dist == 0 ? 0 : (int)power(2, dist - 1, MOD));
          }
          return res;   
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{1, 2}};
    vector<vector<int>> queries1 = {{1, 1}, {1, 2}};
    vector<int> res1 = {0, 1};
    assert(s.assignEdgeWeights(edges1, queries1) == res1);
    vector<vector<int>> edges2 = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    vector<vector<int>> queries2 = {{1, 4}, {3, 4}, {2, 5}};
    vector<int> res2 = {2, 1, 4};
    assert(s.assignEdgeWeights(edges2, queries2) == res2);
    return 0;
}
