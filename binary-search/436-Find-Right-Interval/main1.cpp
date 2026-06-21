#include <cassert>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> starts;
        const int n = intervals.size();
        for (int i = 0; i < n; ++i) starts[intervals[i][0]] = i;
        vector<int> res; res.reserve(n);
        for (const vector<int>& interval : intervals) {
            const auto it = starts.lower_bound(interval[1]);
            res.push_back(it == starts.cend() ? -1 : it->second);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals1 = {{1, 2}};
    vector<int> res1 = {-1};
    assert(s.findRightInterval(intervals1) == res1);
    vector<vector<int>> intervals2 = {{3, 4}, {2, 3}, {1, 2}};
    vector<int> res2 = {-1, 0, 1};
    assert(s.findRightInterval(intervals2) == res2);
    vector<vector<int>> intervals3 = {{1, 4}, {2, 3}, {3, 4}};
    vector<int> res3 = {-1, 2, -1};
    assert(s.findRightInterval(intervals3) == res3);
    return 0;
}
