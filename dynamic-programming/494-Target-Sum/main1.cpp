#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int total = accumulate(nums.cbegin(), nums.cend(), 0);
        if (total < abs(target) || (total - target) & 1) return 0;
        const int n = (total - target) / 2;
        vector<int> dp(n + 1, 0); dp[0] = 1;
        for (const int num : nums) for (int j = n; j >= num; --j) dp[j] += dp[j - num];
        return dp[n];
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 1, 1, 1};
    assert(s.findTargetSumWays(nums1, 3) == 5);
    vector<int> nums2 = {1};
    assert(s.findTargetSumWays(nums2, 1) == 1);
    return 0;
}
