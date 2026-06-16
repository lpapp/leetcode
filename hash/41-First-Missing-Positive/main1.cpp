#include <cassert>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	const int n = nums.size();
    	for (int i = 0; i < n; ++i) while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
    	for (int i = 0; i < n; ++i) if (nums[i] != i + 1) return i + 1;
    	return n + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 0};
    assert(s.firstMissingPositive(nums1) == 3);
    vector<int> nums2 = {3, 4, -1, 1};
    assert(s.firstMissingPositive(nums2) == 2);
    vector<int> nums3 = {7, 8, 9, 11, 12};
    assert(s.firstMissingPositive(nums3) == 1);
    return 0;
}
