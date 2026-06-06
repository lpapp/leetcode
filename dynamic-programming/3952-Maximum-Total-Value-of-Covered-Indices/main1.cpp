#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long dp0 = 0, dp1 = LLONG_MIN / 2;
        for (int i = 0; i < n; ++i) {
            long long newDp0, newDp1;
            if (s[i] == '1') {
                newDp1 = max(dp0, dp1) + nums[i];
                if (i > 0) newDp0 = max(dp0 + nums[i-1], dp1);
                else newDp0 = LLONG_MIN / 2;
            } else {
                newDp0 = max(dp0, dp1), newDp1 = LLONG_MIN / 2;
            }
            dp0 = newDp0, dp1 = newDp1;
        }
        return max(dp0, dp1);
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {9, 2, 6, 1};
    assert(s.maxTotal(nums1, "0101") == 15);
    vector<int> nums2 = {5, 1, 4};
    assert(s.maxTotal(nums2, "001") == 4);
    vector<int> nums3 = {9, 3, 5};
    assert(s.maxTotal(nums3, "011") == 14);
	return 0;
}
