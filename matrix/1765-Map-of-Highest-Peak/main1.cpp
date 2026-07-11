#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<pair<int,int>> q;
        q.reserve(m * n);
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (isWater[i][j]) { res[i][j] = 0; q.emplace_back(i, j); }
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        for (int idx = 0; idx < static_cast<int>(q.size()); ++idx) {
            const auto [ci, cj] = q[idx];
            for (int d = 0; d < 4; ++d) {
                const int x = ci + dirs[d], y = cj + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && res[x][y] == -1) { res[x][y] = res[ci][cj] + 1; q.emplace_back(x, y); }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> isWater1 = {{0, 1}, {0, 0}};
    vector<vector<int>> res1 = {{1, 0}, {2, 1}};
    assert(s.highestPeak(isWater1) == res1);

    vector<vector<int>> isWater2 = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    vector<vector<int>> res2 = {{1, 1, 0}, {0, 1, 1}, {1, 2, 2}};
    assert(s.highestPeak(isWater2) == res2);
    return 0;
}
