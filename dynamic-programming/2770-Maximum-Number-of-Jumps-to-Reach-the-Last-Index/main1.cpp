#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
    	const int length = nums.size();
    	vector<int> dp(length, -1); dp[0] = 0;
    	for (int j = 1; j < length; ++j) for (int i = 0; i < j; ++i) if (dp[i] != -1 && abs((long long)nums[j] - nums[i]) <= target) dp[j] = max(dp[j], dp[i] + 1);
    	return dp[length - 1];
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 3, 6, 4, 1, 2};
    assert(s.maximumJumps(nums1, 2) == 3);
    vector<int> nums2 = {1, 3, 6, 4, 1, 2};
    assert(s.maximumJumps(nums2, 3) == 5);
    vector<int> nums3 = {1, 3, 6, 4, 1, 2};
    assert(s.maximumJumps(nums3, 0) == -1);
	return 0;
}
