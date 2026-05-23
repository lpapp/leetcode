#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        for (int i = 0, n = nums.size(), drops = 0; i < n; ++i) if (nums[i] > nums[(i + 1) % n] && ++drops == 2) return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 4, 5, 1, 2};
    assert(s.check(nums1));
    vector<int> nums2 = {2, 1, 3, 4};
    assert(!s.check(nums2));
    vector<int> nums3 = {1, 2, 3};
    assert(s.check(nums3));
    return 0;
}
