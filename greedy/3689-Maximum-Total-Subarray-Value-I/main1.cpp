#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [mn, mx] = std::ranges::minmax(nums);
        return (long long)k * (mx - mn);       
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 3, 2};
    assert(s.maxTotalValue(nums1, 2) == 4);
    vector<int> nums2 = {4, 2, 5, 1};
    assert(s.maxTotalValue(nums2, 3) == 12);
	return 0;
}
