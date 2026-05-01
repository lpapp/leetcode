#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int curr = 0, sum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) { curr += i * nums[i]; sum += nums[i]; }
        int res = curr;
        for (int i = 1; i < n; curr += sum - n * nums[n - i++], res = max(res, curr));
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {4, 3, 2, 6};
    assert(s.maxRotateFunction(nums1) == 26);
    vector<int> nums2 = {100};
    assert(!s.maxRotateFunction(nums2));
	return 0;
}
