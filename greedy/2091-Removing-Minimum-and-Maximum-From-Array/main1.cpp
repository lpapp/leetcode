#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mi = 0, mx = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[mi]) mi = i;
            else if (nums[i] > nums[mx]) mx = i;
        }
        const auto [l, r] = minmax(mi, mx);
        return min({r + 1, n - l, l + 1 + n - r});
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 10, 7, 5, 4, 1, 8, 6};
    assert(s.minimumDeletions(nums1) == 5);
    vector<int> nums2 = {0, -4, 19, 1, 8, -2, -3, 5};
    assert(s.minimumDeletions(nums2) == 3);
    vector<int> nums3 = {101};
    assert(s.minimumDeletions(nums3) == 1);
    return 0;
}
