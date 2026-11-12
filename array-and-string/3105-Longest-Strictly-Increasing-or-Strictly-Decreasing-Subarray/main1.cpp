#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 0;
        for (int prev = nums[0], inc = 0, dec = 0; const int num : nums) {
            inc = (num > prev) * inc + 1;
            dec = (num < prev) * dec + 1;
            res = ranges::max({res, inc, dec});
            prev = num;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 4, 3, 3, 2};
    assert(s.longestMonotonicSubarray(nums1) == 2);
    vector<int> nums2 = {3, 3, 3, 3};
    assert(s.longestMonotonicSubarray(nums2) == 1);
    vector<int> nums3 = {3, 2, 1};
    assert(s.longestMonotonicSubarray(nums3) == 3);
    return 0;
}
