#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minEnergy(int /*n*/, int brightness, vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        long long totalTime = 0;
        int mergedStart = intervals[0][0], mergedEnd = intervals[0][1];
        for (int i = 1, size = intervals.size(); i < size; ++i) {
            if (intervals[i][0] <= mergedEnd) mergedEnd = max(mergedEnd, intervals[i][1]);
            else { totalTime += mergedEnd - mergedStart + 1; mergedStart = intervals[i][0]; mergedEnd = intervals[i][1]; }
        }
        totalTime += mergedEnd - mergedStart + 1;
        long long minBulbs = ((long long)brightness + 2) / 3;
        return minBulbs * totalTime;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> intervals1 = {{6, 12}};
    assert(s.minEnergy(5, 5, intervals1) == 14);
    vector<vector<int>> intervals2 = {{0, 0}, {2, 2}};
    assert(s.minEnergy(2, 1, intervals2) == 2);
    vector<vector<int>> intervals3 = {{1, 3}, {2, 4}};
    assert(s.minEnergy(4, 2, intervals3) == 4);
	return 0;
}
