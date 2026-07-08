#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n + 1);
        for (vector<int>& e : edges) { g[e[0]].insert(e[1]); g[e[1]].insert(e[0]); }
        vector<int> odd;
        for (int i = 1; i <= n; ++i) if (g[i].size() & 1) odd.push_back(i);
        const int m = odd.size();
        if (!m) return true;
        if (m == 2) {
            const int a = odd[0], b = odd[1];
            if (!g[a].contains(b)) return true;
            for (int c = 1; c <= n; ++c) if (c != a && c != b && !g[a].contains(c) && !g[b].contains(c)) return true;
            return false;
        }
        if (m == 4) {
            const int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            return (!g[a].contains(b) && !g[c].contains(d))
                || (!g[a].contains(c) && !g[b].contains(d))
                || (!g[a].contains(d) && !g[b].contains(c));
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 4}, {2, 5}};
    assert(s.isPossible(5, edges1));
    vector<vector<int>> edges2 = {{1, 2}, {3, 4}};
    assert(s.isPossible(4, edges2));
    vector<vector<int>> edges3 = {{1, 2}, {1, 3}, {1, 4}};
    assert(!s.isPossible(4, edges3));
    return 0;
}
