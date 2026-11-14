#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), prefix[101] = {}, res = INT_MAX;
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];
        for (int i = 0; i + l <= n; ++i)
            for (int j = i + l, end = min(n, i + r); j <= end; ++j) {
                const int sum = prefix[j] - prefix[i];
                if (sum > 0) res = min(res, sum);
            }
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, -2, 1, 4};
    assert(s.minimumSumSubarray(nums1, 2, 3) == 1);
    vector<int> nums2 = {-2, 2, -3, 1};
    assert(s.minimumSumSubarray(nums2, 2, 3) == -1);
    return 0;
}
