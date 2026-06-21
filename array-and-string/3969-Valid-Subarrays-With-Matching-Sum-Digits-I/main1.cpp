#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size(), res = 0;
        for (int l = 0; l < n; ++l) {
            long long sum = 0;
            for (int r = l; r < n; ++r) {
                sum += nums[r];
                if (sum % 10 == x) {
                    long long s = sum;
                    while (s >= 10) s /= 10;
                    if (s == x) ++res;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 100, 1};
    assert(s.countValidSubarrays(nums1, 1) == 4);
    vector<int> nums2 = {1};
    assert(!s.countValidSubarrays(nums2, 2));
    return 0;
}
