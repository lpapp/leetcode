#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        const int n = nums.size();
        vector<int> g(n);
        for (int i = 0, mx = 0; i < n; ++i) { mx = max(mx, nums[i]); g[i] = gcd(nums[i], mx); }
        ranges::sort(g);
        long long res = 0;
        for (int l = 0, r = n - 1; l < r; ++l, --r) res += gcd(g[l], g[r]);
        return res;  
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 6, 4};
    assert(s.gcdSum(nums1) == 2);
    vector<int> nums2 = {3, 6, 2, 8};
    assert(s.gcdSum(nums2) == 5);
    return 0;
}
