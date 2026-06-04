#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1, n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; res = max(res, dp[i++])) for (int j = 0; j < i; ++j) if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(s.lengthOfLIS(nums1) == 4);
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    assert(s.lengthOfLIS(nums2) == 4);
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    assert(s.lengthOfLIS(nums3) == 1);
	return 0;
}
