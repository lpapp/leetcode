#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        return ranges::count(nums, nums[nums.size() / 2]) == 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    assert(s.isMiddleElementUnique(nums1));
    vector<int> nums2 = {1, 2, 2};
    assert(!s.isMiddleElementUnique(nums2));
    return 0;
}
