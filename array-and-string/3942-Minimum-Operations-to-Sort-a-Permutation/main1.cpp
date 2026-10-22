#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), zero = 0, desc = 0, asc = 0, ans = INT_MAX;
        if (n <= 1) return 0;
        for (int i = 0; i < n; ++i) {
            const int j = i + 1 == n ? 0 : i + 1;
            if (nums[i] > nums[j]) ++desc; else ++asc;
            if (!nums[i]) zero = i;
        }
        if (desc == 1) ans = min({ans, zero, n - zero + 2});
        if (asc == 1) ans = min({ans, zero + 2, n - zero});
        return ans == INT_MAX ? -1 : ans;       
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {0, 2, 1};
    assert(s.minOperations(nums1) == 2);
    vector<int> nums2 = {1, 0, 2};
    assert(s.minOperations(nums2) == 2);
    vector<int> nums3 = {2, 0, 1, 3};
    assert(s.minOperations(nums3) == -1);
    return 0;
}
