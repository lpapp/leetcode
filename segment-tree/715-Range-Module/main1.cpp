#include <cassert>
#include <map>
#include <vector>

using namespace std;

class RangeModule {
    map<int, int> intervals;
public:
    RangeModule() = default;
    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin() && prev(it)->second >= left) { --it; left = it->first; }
        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right;
    }
    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        return prev(it)->second >= right;
    }
    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin() && prev(it)->second >= left) --it;
        vector<pair<int, int>> readd;
        while (it != intervals.end() && it->first < right) {
            if (it->first < left) readd.emplace_back(it->first, left);
            if (it->second > right) readd.emplace_back(right, it->second);
            it = intervals.erase(it);
        }
        for (const auto& [s, e] : readd) intervals[s] = e;
    }
};

int main()
{
    RangeModule rangeModule;
    rangeModule.addRange(10, 20);
    rangeModule.removeRange(14, 16);
    assert(rangeModule.queryRange(10, 14));
    assert(!rangeModule.queryRange(13, 15));
    assert(rangeModule.queryRange(16, 17));
    return 0;
}
