#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	ranges::sort(nums);
    	int res = nums[0] + nums[1] + nums[2];
    	for (int i = 0, n = nums.size(); i < n - 2; ++i) {
    	    for (int j = i + 1, k = n - 1; j < k; ) {
    	        const int s = nums[i] + nums[j] + nums[k];
    	        if (s == target) return s;
    	        if (abs(s - target) < abs(res - target)) res = s;
    	        if (s < target) ++j;
    	        else --k;
    	    }
    	}
    	return res;
    }
};

int main()
{
    Solution s;
	vector<int> nums1 = {-1, 2, 1, -4};
    assert(s.threeSumClosest(nums1, 1) == 2);
	vector<int> nums2 = {0, 0, 0};
    assert(!s.threeSumClosest(nums2, 1));
    return 0;
}
