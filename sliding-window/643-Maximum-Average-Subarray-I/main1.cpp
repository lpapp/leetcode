#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = reduce(nums.cbegin(), nums.cbegin() + k, 0), maxSum = sum;
        for (int i = k, n = nums.size(); i < n; ++i) { sum += nums[i] - nums[i - k]; maxSum = max(maxSum, sum); }
        return static_cast<double>(maxSum) / k;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    assert(s.findMaxAverage(nums1, 4) == 12.75000);
    vector<int> nums2 = {5};
    assert(s.findMaxAverage(nums2, 1) == 5.00000);
    return 0;
}
