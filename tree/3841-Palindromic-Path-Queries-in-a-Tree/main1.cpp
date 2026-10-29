#include <cassert>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        constexpr int LOG = 16;
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) { adj[edge[0]].push_back(edge[1]); adj[edge[1]].push_back(edge[0]); }
        vector<int> tin(n), tout(n), depth(n), base(n), next(n);
        vector<vector<int>> up(LOG, vector<int>(n));
        int timer = 0;
        base[0] = 1 << (s[0] - 'a');
        tin[0] = timer++;
        for (vector<int> stk({0}); !stk.empty(); ) {
            const int u = stk.back();
            if (next[u] == (int)adj[u].size()) { tout[u] = timer - 1; stk.pop_back(); continue; }
            const int v = adj[u][next[u]++];
            if (v == up[0][u]) continue;
            up[0][v] = u;
            depth[v] = depth[u] + 1;
            base[v] = base[u] ^ (1 << (s[v] - 'a'));
            tin[v] = timer++;
            stk.push_back(v);
        }
        for (int k = 1; k < LOG; ++k) for (int v = 0; v < n; ++v) up[k][v] = up[k - 1][up[k - 1][v]];
        vector<int> bit(n + 2);
        auto add = [&](int pos, int val) { for (++pos; pos <= n + 1; pos += pos & -pos) bit[pos] ^= val; };
        auto pathMask = [&](int v) { int res = base[v]; for (int pos = tin[v] + 1; pos > 0; pos -= pos & -pos) res ^= bit[pos]; return res; };
        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            for (int k = 0, diff = depth[a] - depth[b]; k < LOG; ++k) if ((diff >> k) & 1) a = up[k][a];
            if (a == b) return a;
            for (int k = LOG - 1; k >= 0; --k) if (up[k][a] != up[k][b]) { a = up[k][a]; b = up[k][b]; }
            return up[0][a];
        };
        vector<bool> res;
        for (const string& query : queries) {
            istringstream in(query);
            string type; int u;
            in >> type >> u;
            if (type[0] == 'u') {
                char c; in >> c;
                const int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                add(tin[u], delta);
                add(tout[u] + 1, delta);
                s[u] = c;
            } else {
                int v; in >> v;
                const int mask = pathMask(u) ^ pathMask(v) ^ (1 << (s[lca(u, v)] - 'a'));
                res.push_back(!(mask & (mask - 1)));
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
    vector<string> queries1 = {"query 0 2", "update 1 b", "query 0 2"};
    vector<bool> res1 = {true, false};
    assert(s.palindromePath(3, edges1, "aac", queries1) == res1);
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}};
    vector<string> queries2 = {"query 1 2", "update 0 b", "query 2 3", "update 3 a", "query 1 3"};
    vector<bool> res2 = {false, false, true};
    assert(s.palindromePath(4, edges2, "abca", queries2) == res2);
    return 0;
}
