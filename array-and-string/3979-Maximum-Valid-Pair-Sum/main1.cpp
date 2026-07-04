#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        const int n = nums.size();
        long long res = LLONG_MIN;
        int prefixMax = nums[0];
        for (int j = k; j < n; ++j) {
            res = max(res, static_cast<long long>(prefixMax + nums[j]));
            prefixMax = max(prefixMax, nums[j - k + 1]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3, 5, 2, 8};
    assert(s.maxValidPairSum(nums1, 2) == 13);
    vector<int> nums2 = {5, 1, 9};
    assert(s.maxValidPairSum(nums2, 1) == 14);
    return 0;
}
