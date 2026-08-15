#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(), xorAll = 0;
        bool hasNonZero = false;
        for (const int num : nums) {
            xorAll ^= num;
            if (num) hasNonZero = true;
        }
        if (!hasNonZero) return 0;
        if (xorAll) return n;
        return n - 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    assert(s.longestSubsequence(nums1) == 2);
    vector<int> nums2 = {2, 3, 4};
    assert(s.longestSubsequence(nums2) == 3);
    return 0;
}
