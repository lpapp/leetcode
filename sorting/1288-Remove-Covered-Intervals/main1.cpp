#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](vector<int>& a, vector<int>& b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        int res = 0, maxEnd = 0;
        for (const vector<int>& interval : intervals) if (interval[1] > maxEnd) { ++res; maxEnd = interval[1]; }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals1 = {{1, 4}, {3, 6}, {2, 8}};
    assert(s.removeCoveredIntervals(intervals1) == 2);
    vector<vector<int>> intervals2 = {{1, 4}, {2, 3}};
    assert(s.removeCoveredIntervals(intervals2) == 1);
    return 0;
}
