#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int res = 0;
        for (int r = 0, l = 0, n = nums.size(); r < n; ++r) {
            ++freq[nums[r]];
            while (freq[nums[r]] > k) --freq[nums[l++]];
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 1, 2, 3, 1, 2};
    assert(s.maxSubarrayLength(nums1, 2) == 6);
    vector<int> nums2 = {1, 2, 1, 2, 1, 2, 1, 2};
    assert(s.maxSubarrayLength(nums2, 1) == 2);
    vector<int> nums3 = {5, 5, 5, 5, 5, 5, 5};
    assert(s.maxSubarrayLength(nums3, 4) == 4);
    vector<int> nums4 = {1, 4, 4, 3};
    assert(s.maxSubarrayLength(nums4, 1) == 2);
    return 0;
}
