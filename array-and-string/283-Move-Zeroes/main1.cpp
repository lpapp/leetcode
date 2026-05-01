#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t k = 0;
        for (size_t i = 0; i < nums.size(); ++i) if (nums[i]) nums[k++] = nums[i];
        for (; k < nums.size(); ++k) nums[k] = 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {0, 1, 0, 3, 12};
    s.moveZeroes(nums1);
    assert((nums1 == vector<int>{1, 3, 12, 0, 0}));
    vector<int> nums2 = {0};
    s.moveZeroes(nums2);
    assert((nums2 == vector<int>{0}));
    return 0;
}
