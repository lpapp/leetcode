#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;
        for (int b = 0, n = nums.size(); b < n && res; b += 1024) for (int i = b,
 e = min(n, b + 1024); i < e; ++i) res &= i != nums[i] ? nums[i] : -1;
        return max(res, 0);
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {0, 3, 2, 1};
    assert(s.sortPermutation(nums1) == 1);
    vector<int> nums2 = {0, 1, 3, 2};
    assert(s.sortPermutation(nums2) == 2);
    vector<int> nums3 = {3, 2, 1, 0};
    assert(s.sortPermutation(nums3) == 0);
    return 0;
}
