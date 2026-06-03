#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    int minEnd(vector<int>& firstStart, vector<int>& firstDuration, vector<int>& secondStart, vector<int>& secondDuration) {
        int minFirstEnd = numeric_limits<int>::max();
        for (int i = 0, n = firstStart.size(); i < n; ++i) minFirstEnd = min(minFirstEnd, firstStart[i] + firstDuration[i]);
        int res = numeric_limits<int>::max();
        for (int i = 0, n = secondStart.size(); i < n; ++i) res = min(res, max(minFirstEnd, secondStart[i]) + secondDuration[i]);
        return res;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(minEnd(landStartTime, landDuration, waterStartTime, waterDuration), minEnd(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};

int main()
{
	Solution s;
    vector<int> landStartTime1 = {2, 8};
    vector<int> landDuration1 = {4, 1};
    vector<int> waterStartTime1 = {6};
    vector<int> waterDuration1 = {3};
    assert(s.earliestFinishTime(landStartTime1, landDuration1, waterStartTime1, waterDuration1) == 9);
    vector<int> landStartTime2 = {5};
    vector<int> landDuration2 = {3};
    vector<int> waterStartTime2 = {1};
    vector<int> waterDuration2 = {10};
    assert(s.earliestFinishTime(landStartTime2, landDuration2, waterStartTime2, waterDuration2) == 14);
	return 0;
}
