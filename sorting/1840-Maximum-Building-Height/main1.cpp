#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        ranges::sort(restrictions);
        if (restrictions.back()[0] != n) restrictions.push_back({n, n - 1});
        for (int i = 1, m = restrictions.size(); i < m; ++i) restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        for (int i = restrictions.size() - 2; i > 0; --i) restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        int res = 0;
        for (int i = 0, m = restrictions.size() - 1; i < m; ++i) res = max(res, (restrictions[i][1] + restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]) / 2);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> restrictions1 = {{2, 1}, {4, 1}};
    assert(s.maxBuilding(5, restrictions1) == 2);
    vector<vector<int>> restrictions2 = {};
    assert(s.maxBuilding(6, restrictions2) == 5);
    vector<vector<int>> restrictions3 = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
    assert(s.maxBuilding(10, restrictions3) == 5);
    return 0;
}
