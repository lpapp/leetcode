#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        long total = accumulate(nums.begin(), nums.end(), 0L), target = total - x;
        if (target < 0) return -1;
        if (target == 0) return n;
        long sum = 0;
        int maxLen = -1;
        for (int left = 0, right = 0; right < n; ++right) {
            for (sum += nums[right]; sum > target; sum -= nums[left++]);
            if (sum == target) maxLen = max(maxLen, right - left + 1);
        }
        return maxLen == -1 ? -1 : n - maxLen;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 4, 2, 3};
    assert(s.minOperations(nums1, 5) == 2);
    vector<int> nums2 = {5, 6, 7, 8, 9};
    assert(s.minOperations(nums2, 4) == -1);
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    assert(s.minOperations(nums3, 10) == 5);
    return 0;
}
