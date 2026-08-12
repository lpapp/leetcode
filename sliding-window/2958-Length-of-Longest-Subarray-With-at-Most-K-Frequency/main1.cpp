#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, n = nums.size();
        for (int r = 0; r < n; ++r) {
            ++freq[nums[r]];
            if (freq[nums[r]] > k) --freq[nums[l++]];
        }
        return n - l;
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
    return 0;
}
