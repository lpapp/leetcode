#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        for (int r = 0, n = nums.size(); r < n; ++r) if ((k -= nums[r] ^ 1) < 0) k += nums[l++] ^ 1;
        return nums.size() - l;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    assert(s.longestOnes(nums1, 2) == 6);
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    assert(s.longestOnes(nums2, 3) == 10);
    return 0;
}
