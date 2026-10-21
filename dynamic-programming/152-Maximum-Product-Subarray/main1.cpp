#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, n = nums.size(), prefix = 1, suffix = 1; i < n; ++i) {
            prefix = (prefix ? prefix : 1) * nums[i];
            suffix = (suffix ? suffix : 1) * nums[n - 1 - i];
            res = max({res, prefix, suffix});
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 3, -2, 4};
    assert(s.maxProduct(nums1) == 6);
    vector<int> nums2 = {-2, 0, -1};
    assert(s.maxProduct(nums2) == 0);
    return 0;
}
