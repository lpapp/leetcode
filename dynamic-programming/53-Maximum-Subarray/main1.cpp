#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], current = nums[0];
        for (int i = 1, n = nums.size(); i < n; ++i) { current = max(current, 0) + nums[i]; res = max(res, current); }
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	assert(s.maxSubArray(nums1) == 6);
	vector<int> nums2 = {1};
	assert(s.maxSubArray(nums2) == 1);
	vector<int> nums3 = {5, 4, -1, 7, 8};
	assert(s.maxSubArray(nums3) == 23);
	return 0;
}
