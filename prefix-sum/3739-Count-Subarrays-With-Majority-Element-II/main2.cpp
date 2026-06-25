#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int res = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            for (int j = i, count = 0; j < n; ++j) {
                count += nums[j] == target;
                if (2 * count > j - i + 1) ++res;
            }
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 2, 2, 3};
    assert(s.countMajoritySubarrays(nums1, 2) == 5);
    vector<int> nums2 = {1, 1, 1, 1};
    assert(s.countMajoritySubarrays(nums2, 1) == 10);
    vector<int> nums3 = {1, 2, 3};
    assert(!s.countMajoritySubarrays(nums3, 4));
	return 0;
}
