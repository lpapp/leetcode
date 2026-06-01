#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int INF = 1 << 30;
        int minPrefixSum = 0, maxPrefixSum = -INF;
        int maxSubarraySum = -INF, minSubarraySum = INF;
        int prefixSum = 0;
        for (const int num : nums) {
            prefixSum += num;
            maxSubarraySum = max(maxSubarraySum, prefixSum - minPrefixSum);
            minSubarraySum = min(minSubarraySum, prefixSum - maxPrefixSum);
            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }
        return max(maxSubarraySum, prefixSum - minSubarraySum);
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {1, -2, 3, -2};
	assert(s.maxSubarraySumCircular(nums1) == 3);
	vector<int> nums2 = {5, -3, 5};
	assert(s.maxSubarraySumCircular(nums2) == 10);
	vector<int> nums3 = {-3, -2, -3};
	assert(s.maxSubarraySumCircular(nums3) == -2);
	return 0;
}
