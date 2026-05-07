#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) prefix[i] = max(prefix[i - 1], nums[i]);
        for (int i = n - 1, suffixMin = numeric_limits<int>::max(); i >= 0; suffixMin = min(suffixMin, nums[i--])) { if (prefix[i] > suffixMin) res[i] = (i + 1 < n) ? res[i + 1] : prefix[i]; else res[i] = prefix[i];
        }
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {2, 1, 3};
	vector<int> res1 = {2, 2, 3};
	assert(s.maxValue(nums1) == res1);
	vector<int> nums2 = {2, 3, 1};
	vector<int> res2 = {3, 3, 3};
	assert(s.maxValue(nums2) == res2);
	return 0;
}
