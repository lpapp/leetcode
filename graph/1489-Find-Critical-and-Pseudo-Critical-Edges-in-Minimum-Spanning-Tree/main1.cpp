#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    struct UF {
        vector<int> p; int comp;
        UF(int n) : p(n), comp(n) { iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; p[a] = b; --comp; return true; }
    };
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        const int m = edges.size();
        for (int i = 0; i < m; ++i) edges[i].push_back(i);
        ranges::sort(edges, [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
        UF base(n);
        int mst = 0;
        vector<char> inMst(m, 0);
        for (int j = 0; j < m; ++j) {
            const vector<int>& e = edges[j];
            if (base.unite(e[0], e[1])) { mst += e[2]; inMst[j] = 1; }
        }
        vector<vector<int>> res(2);
        for (int j = 0; j < m; ++j) {
            const vector<int>& cur = edges[j];
            const int idx = cur[3];
            if (inMst[j]) {
                UF without(n);
                int w = 0;
                for (int k = 0; k < m; ++k) if (k != j && without.unite(edges[k][0], edges[k][1])) w += edges[k][2];
                if (without.comp > 1 || w > mst) { res[0].push_back(idx); continue; }
                res[1].push_back(idx);
            } else {
                UF with(n);
                with.unite(cur[0], cur[1]);
                int w2 = cur[2];
                for (int k = 0; k < m; ++k) if (k != j && with.unite(edges[k][0], edges[k][1])) w2 += edges[k][2];
                if (w2 == mst) res[1].push_back(idx);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
    vector<vector<int>> res1 = {{0, 1}, {2, 3, 4, 5}};
    assert(s.findCriticalAndPseudoCriticalEdges(5, edges1) == res1);
    vector<vector<int>> edges2 = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}};
    vector<vector<int>> res2 = {{}, {0, 1, 2, 3}};
    assert(s.findCriticalAndPseudoCriticalEdges(4, edges2) == res2);
    return 0;
}
