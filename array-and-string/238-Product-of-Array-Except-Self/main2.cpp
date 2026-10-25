#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int numsLength = nums.size();
        vector<int> result(numsLength);
        for (int i = 0, left = 1; i < numsLength; ++i) { result[i] = left; left *= nums[i]; }
        for (int i = numsLength - 1, right = 1; i >= 0; --i) { result[i] *= right; right *= nums[i]; }
        return result;
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
