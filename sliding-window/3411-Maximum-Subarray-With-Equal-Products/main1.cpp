#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 2;
        for (int left = 0, right = 0, n = nums.size(), lastSeen[8] = {}, primes[] = {2, 3, 5, 7}; right < n; ++right) {
            for (const int prime : primes) if (nums[right] % prime == 0) {
                left = max(left, lastSeen[prime]);
                lastSeen[prime] = right + 1;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 1, 2, 1, 1, 1};
    assert(s.maxLength(nums1) == 5);
    vector<int> nums2 = {2, 3, 4, 5, 6};
    assert(s.maxLength(nums2) == 3);
    vector<int> nums3 = {1, 2, 3, 1, 4, 5, 1};
    assert(s.maxLength(nums3) == 5);
    return 0;
}
