#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
    	int right[2]{};
    	for (int i = 0, n = nums.size(); i < n; ++i) right[i & 1] += nums[i];
    	int res = 0;
    	for (int i = 0, n = nums.size(), left[2]{}; i < n; ++i) {
    	    right[i & 1] -= nums[i];
    	    res += left[0] + right[1] == left[1] + right[0];
    	    left[i & 1] += nums[i];
    	}
    	return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {2, 1, 6, 4};
    assert(s.waysToMakeFair(nums1) == 1);
    vector<int> nums2 = {1, 1, 1};
    assert(s.waysToMakeFair(nums2) == 3);
    vector<int> nums3 = {1, 2, 3};
    assert(!s.waysToMakeFair(nums3));
	return 0;
}
