#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int n = bloomDay.size();
        if (static_cast<long long>(m) * k > n) return -1;
        auto [l, r] = ranges::minmax(bloomDay);
        while (l < r) {
            int mid = (l + r) >> 1, bouquets = 0, consec = 0;
            for (int d : bloomDay) {
                consec = (d <= mid) ? consec + 1 : 0;
                if (consec == k) { ++bouquets; consec = 0; }
            }
            if (bouquets >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main()
{
    Solution s;
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    assert(s.minDays(bloomDay1, 3, 1) == 3);
    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    assert(s.minDays(bloomDay2, 3, 2) == -1);
    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    assert(s.minDays(bloomDay3, 2, 3) == 12);
    return 0;
}
