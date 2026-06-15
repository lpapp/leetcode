#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    	int l = 0;
    	for (int r = 0, k = 1, n = nums.size(); r < n; ++r) if ((k -= nums[r] ^ 1) < 0) k += nums[l++] ^ 1;
    	return nums.size() - l - 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 0, 1};
    assert(s.longestSubarray(nums1) == 3);
    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    assert(s.longestSubarray(nums2) == 5);
    vector<int> nums3 = {1, 1, 1};
    assert(s.longestSubarray(nums3) == 2);
    return 0;
}
