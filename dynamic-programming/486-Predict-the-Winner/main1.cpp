#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = nums[i];
            for (int j = i + 1; j < n; ++j) dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
        return dp[n - 1] >= 0;       
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 5, 2};
    assert(!s.predictTheWinner(nums1));
    vector<int> nums2 = {1, 5, 233, 7};
    assert(s.predictTheWinner(nums2));
    return 0;
}
