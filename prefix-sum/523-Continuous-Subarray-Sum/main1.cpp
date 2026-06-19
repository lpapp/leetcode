#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash{{0, -1}};
        for (int i = 0, sum = 0, n = nums.size(); i < n; ++i) {
            sum = (sum + nums[i]) % k;
            const auto [it, inserted] = hash.try_emplace(sum, i);
            if (!inserted && i - it->second > 1) return true;
        }
        return false;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {23, 2, 4, 6, 7};
    assert(s.checkSubarraySum(nums1, 6));
    vector<int> nums2 = {23, 2, 6, 4, 7};
    assert(s.checkSubarraySum(nums2, 6));
    vector<int> nums3 = {23, 2, 6, 4, 7};
    assert(!s.checkSubarraySum(nums3, 13));
	return 0;
}
