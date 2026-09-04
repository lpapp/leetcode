#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), prefixMax = nums[0];
        vector<int> suffixMin(n); suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        for (int i = 0; i < n; ++i) {
            prefixMax = max(prefixMax, nums[i]);
            if (prefixMax - suffixMin[i] <= k) return i;
        }
        return -1;        
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {5, 0, 1, 4};
    assert(s.firstStableIndex(nums1, 3) == 3);
    vector<int> nums2 = {3, 2, 1};
    assert(s.firstStableIndex(nums2, 1) == -1);
    vector<int> nums3 = {0};
    assert(s.firstStableIndex(nums3, 0) == 0);
    return 0;
}
