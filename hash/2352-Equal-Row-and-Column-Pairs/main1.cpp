#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        auto hash = [](const vector<int>& v) { size_t seed = v.size(); for (auto x : v) seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2); return seed; };
        unordered_map<vector<int>, int, decltype(hash)> freq(0, hash);
        for (const vector<int>& row : grid) ++freq[row];
        int res = 0;
        vector<int> column(n);
        for (int j = 0; j < n; ++j) { for (int i = 0; i < n; ++i) column[i] = grid[i][j]; res += freq[column]; }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    assert(s.equalPairs(grid1) == 1);
    vector<vector<int>> grid2 = {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}
    };
    assert(s.equalPairs(grid2) == 3);
    return 0;
}
