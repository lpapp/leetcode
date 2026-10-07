#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        constexpr int maxValue = 10001;
        vector<int> delta(2 * maxValue + 3, 0);
        for (const vector<int>& interval : intervals) { ++delta[2 * interval[0]]; --delta[2 * interval[1] + 1]; }
        vector<vector<int>> res;
        for (int balance = 0, start = -1, value = 0; value <= 2 * maxValue + 1; ++value) {
            balance += delta[value];
            if (balance > 0 && start == -1) start = value;
            else if (!balance && start != -1) { res.push_back({start / 2, (value - 1) / 2}); start = -1; }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res1 = {{1, 6}, {8, 10}, {15, 18}};
    assert(s.merge(intervals1) == res1);
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<vector<int>> res2 = {{1, 5}};
    assert(s.merge(intervals2) == res2);
    vector<vector<int>> intervals3 = {{4, 7}, {1, 4}};
    vector<vector<int>> res3 = {{1, 7}};
    assert(s.merge(intervals3) == res3);
    vector<vector<int>> intervals4 = {{1, 4}, {5, 6}};
    vector<vector<int>> res4 = {{1, 4}, {5, 6}};
    assert(s.merge(intervals4) == res4);
    return 0;
}
