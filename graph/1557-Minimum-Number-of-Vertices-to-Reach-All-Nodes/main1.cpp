#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n, false);
        for (vector<int>& edge : edges) hasIncoming[edge[1]] = true;
        vector<int> res;
        for (int i = 0; i < n; ++i) if (!hasIncoming[i]) res.push_back(i);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    vector<int> res1 = {0, 3};
    assert(s.findSmallestSetOfVertices(6, edges1) == res1);

    vector<vector<int>> edges2 = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
    vector<int> res2 = {0, 2, 3};
    assert(s.findSmallestSetOfVertices(5, edges2) == res2);
    return 0;
}
