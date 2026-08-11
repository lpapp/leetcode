#include <array>
#include <bitset>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0];
        for (int i = 1, n = nums.size(); i < n && nums[i] == nums[i - 1] + 1; ++i) s += nums[i];
        bitset<51> present;
        for (int num : nums) present[num] = 1;
        while (s < 51 && present[s]) ++s;
        return s;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 2, 5};
    assert(s.missingInteger(nums1) == 6);
    vector<int> nums2 = {3, 4, 5, 1, 12, 14, 13};
    assert(s.missingInteger(nums2) == 15);
    return 0;
}
