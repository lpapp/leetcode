#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (end < intervals[i][0]) { res.push_back({start, end}); start = intervals[i][0]; end = intervals[i][1]; }
			else end = max(end, intervals[i][1]);
        }
        res.push_back({start, end});
        return res;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> intervals1 = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    vector<vector<int>> res1 = {{1, 6}, {8, 10}, {15, 18}};
    assert(s.merge(intervals1) == res1);
    vector<vector<int>> intervals2 = { {1, 4}, {4, 5}};
    vector<vector<int>> res2 = {{1, 5}};
    assert(s.merge(intervals2) == res2);
    vector<vector<int>> intervals3 = { {4, 7}, {1, 4}};
    vector<vector<int>> res3 = {{1, 7}};
    assert(s.merge(intervals3) == res3);
	return 0;
}
