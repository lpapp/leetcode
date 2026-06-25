#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
    	const int n = nums.size();
    	vector<int> pref(n + 1);
    	for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
    	vector<int> sorted = pref;
    	ranges::sort(sorted);
    	sorted.erase(ranges::unique(sorted).begin(), sorted.end());
    	const int m = sorted.size();
    	vector<int> bit(m + 1);
        auto update = [&](int i) { for (++i; i <= m; i += i & -i) ++bit[i]; };
        auto query = [&](int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; };
    	long long res = 0;
    	for (int k = 0; k <= n; ++k) {
    	    const int rank = ranges::lower_bound(sorted, pref[k]) - sorted.begin();
    	    res += query(rank);
    	    update(rank);
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
