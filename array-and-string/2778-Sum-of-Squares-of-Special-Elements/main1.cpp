#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        for (int i = 1, n = nums.size(); i <= n; ++i) if (n % i == 0) ans += nums[i-1] * nums[i-1];
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4};
    assert(s.sumOfSquares(nums1) == 21);
    vector<int> nums2 = {2, 7, 1, 19, 18, 3};
    assert(s.sumOfSquares(nums2) == 63);
    return 0;
}
