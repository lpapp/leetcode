#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int n = nums.size();
        ranges::nth_element(nums, nums.begin() + n / 2);
        long long res = 0;
        for (const int median = nums[n / 2]; const int num : nums) res += abs((long long)num - median);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    assert(s.minMoves2(nums1) == 2);
    vector<int> nums2 = {1, 10, 2, 9};
    assert(s.minMoves2(nums2) == 16);
    return 0;
}
