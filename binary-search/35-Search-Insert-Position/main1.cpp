#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), first = -1;
        for (int left = 0, right = n -1; left <= right;) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) { first = mid; right = mid - 1; }
            else left = mid + 1;
        }
        return first != -1 ? first : n;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 3, 5, 6};
    assert(s.searchInsert(nums1, 5) == 2);
    vector<int> nums2 = {1, 3, 5, 6};
    assert(s.searchInsert(nums2, 2) == 1);
    vector<int> nums3 = {1, 3, 5, 6};
    assert(s.searchInsert(nums3, 7) == 4);
	return 0;
}
