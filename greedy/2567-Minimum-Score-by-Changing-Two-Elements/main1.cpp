#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int lo1 = INT_MAX, lo2 = INT_MAX, lo3 = INT_MAX, hi1 = 0, hi2 = 0, hi3 = 0;
        for (const int x : nums) {
            if (x < lo3) { lo3 = x; if (lo3 < lo2) swap(lo3, lo2); if (lo2 < lo1) swap(lo2, lo1); }
            if (x > hi3) { hi3 = x; if (hi3 > hi2) swap(hi3, hi2); if (hi2 > hi1) swap(hi2, hi1); }
        }
        return min({hi1 - lo3, hi3 - lo1, hi2 - lo2});
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 4, 7, 8, 5};
    assert(s.minimizeSum(nums1) == 3);
    vector<int> nums2 = {1, 4, 3};
    assert(s.minimizeSum(nums2) == 0);
    return 0;
}
