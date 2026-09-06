#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        for (int prev2 = 0; const int num : nums) {
            const int cur = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    assert(s.rob(nums1) == 4);
    vector<int> nums2 = {2, 7, 9, 3, 1};
    assert(s.rob(nums2) == 12);
    return 0;
}
