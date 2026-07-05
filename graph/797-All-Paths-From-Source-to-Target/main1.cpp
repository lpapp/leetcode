#include <cassert>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {0};
        const int target = graph.size() - 1;
        function<void(int)> dfs = [&](int node) {
            if (node == target) { res.push_back(path); return; }
            for (int next : graph[node]) { path.push_back(next); dfs(next); path.pop_back(); }
        };
        dfs(0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph1 = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> res1 = {{0, 1, 3}, {0, 2, 3}};
    assert(s.allPathsSourceTarget(graph1) == res1);
    vector<vector<int>> graph2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    vector<vector<int>> res2 = {{0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4}};
    assert(s.allPathsSourceTarget(graph2) == res2);
    return 0;
}
