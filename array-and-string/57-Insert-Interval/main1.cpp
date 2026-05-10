#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.emplace_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) res.emplace_back(intervals[i]);
            else res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> res1 = {{1, 5}, {6, 9}};
    assert(s.insert(intervals1, newInterval1) == res1);
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> res2 = {{1, 2}, {3, 10}, {12, 16}};
    assert(s.insert(intervals2, newInterval2) == res2);
	return 0;
}
