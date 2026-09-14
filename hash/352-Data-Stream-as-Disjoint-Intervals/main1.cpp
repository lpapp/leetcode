#include <cassert>
#include <map>
#include <vector>

using namespace std;

class SummaryRanges {
    map<int, int> intervals;
public:
    SummaryRanges() = default;
    void addNum(int value) {
        auto rightInterval = intervals.upper_bound(value);
        auto leftInterval = (rightInterval == intervals.begin()) ? intervals.end() : prev(rightInterval);

        if (leftInterval != intervals.end() && rightInterval != intervals.end() &&
            leftInterval->second + 1 == value && rightInterval->first - 1 == value) {
            leftInterval->second = rightInterval->second;
            intervals.erase(rightInterval);
        } else if (leftInterval != intervals.end() && value <= leftInterval->second + 1) {
            leftInterval->second = max(value, leftInterval->second);
        } else if (rightInterval != intervals.end() && value >= rightInterval->first - 1) {
            int newEnd = rightInterval->second;
            int newStart = min(value, rightInterval->first);
            intervals.erase(rightInterval);
            intervals[newStart] = newEnd;
        } else {
            intervals[value] = value;
        }
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (const auto& [start, end] : intervals) result.push_back({start, end});
        return result;
    }
};

int main()
{
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);
    vector<vector<int>> res1 = {{1, 1}};
    assert(summaryRanges.getIntervals() == res1);
    summaryRanges.addNum(3);
    vector<vector<int>> res2 = {{1, 1}, {3, 3}};
    assert(summaryRanges.getIntervals() == res2);
    summaryRanges.addNum(7);
    vector<vector<int>> res3 = {{1, 1}, {3, 3}, {7, 7}};
    assert(summaryRanges.getIntervals() == res3);
    summaryRanges.addNum(2);
    vector<vector<int>> res4 = {{1, 3}, {7, 7}};
    assert(summaryRanges.getIntervals() == res4);
    summaryRanges.addNum(6);
    vector<vector<int>> res5 = {{1, 3}, {6, 7}};
    assert(summaryRanges.getIntervals() == res5);
    return 0;
}
