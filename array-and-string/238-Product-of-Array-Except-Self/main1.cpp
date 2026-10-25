#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int n = nums.size(), i = 0, j = n - 1, left = 1, right = 1; i < n; ++i, --j) { res[i] *= left; left *= nums[i]; res[j] *= right; right *= nums[j]; }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> res1 = {24, 12, 8, 6};
    assert(s.productExceptSelf(nums1) == res1);
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> res2 = {0, 0, 9, 0, 0};
    assert(s.productExceptSelf(nums2) == res2);
    return 0;
}
