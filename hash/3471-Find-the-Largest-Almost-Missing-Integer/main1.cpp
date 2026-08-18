#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k == n) return ranges::max(nums);
        if (k == 1) {
            int freq[51] = {};
            for (const int num : nums) ++freq[num];
            for (int i = 50; i >= 0; --i) if (freq[i] == 1) return i;
            return -1;
        }
        int res = -1;
        if (ranges::count(nums, nums[0]) == 1) res = nums[0];
        if (ranges::count(nums, nums[n - 1]) == 1) res = max(res, nums[n - 1]);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 9, 2, 1, 7};
    assert(s.largestInteger(nums1, 3) == 7);
    vector<int> nums2 = {3, 9, 7, 2, 1, 7};
    assert(s.largestInteger(nums2, 4) == 3);
    vector<int> nums3 = {0, 0};
    assert(s.largestInteger(nums3, 1) == -1);
    return 0;
}
