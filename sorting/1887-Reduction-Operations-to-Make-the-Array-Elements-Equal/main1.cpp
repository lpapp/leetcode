#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ranges::sort(nums);
        int res = 0;
        for (int i = 1, n = nums.size(), operations = 0; i < n; ++i) {
            if (nums[i] != nums[i - 1]) ++operations;
            res += operations;
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {5, 1, 3};
    assert(s.reductionOperations(nums1) == 3);
    vector<int> nums2 = {1, 1, 1};
    assert(!s.reductionOperations(nums2));
    vector<int> nums3 = {1, 1, 2, 2, 3};
    assert(s.reductionOperations(nums3) == 4);
	return 0;
}
