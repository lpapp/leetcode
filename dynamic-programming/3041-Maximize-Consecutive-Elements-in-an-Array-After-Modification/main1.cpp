#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        int res = 1;
        for (int n = nums.size(), i = 0, j, pv = -5, pe0 = 0, pe1 = 0; i < n; i = j) {
            const int v = nums[i];
            for (j = i; j < n && nums[j] == v; ++j);
            const int below = pv == v - 1 ? pe0 : pv == v - 2 ? pe1 : 0, same = pv == v - 1 ? pe1 : 0;
            const int e0 = below + 1, e1 = max(same + 1, j - i > 1 ? e0 + 1 : 0);
            res = max({res, e0, e1}), pv = v, pe0 = e0, pe1 = e1;
        }
        return res;     
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 1, 5, 1, 1};
    assert(s.maxSelectedElements(nums1) == 3);
    vector<int> nums2 = {1, 4, 7, 10};
    assert(s.maxSelectedElements(nums2) == 1);
    return 0;
}
