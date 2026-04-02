#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int left = 0, right = nums.size() - 1; left <= right;) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums1, 0) << endl;
	vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums2, 3) << endl;
	vector<int> nums3 = {1};
    cout << s.search(nums3, 0) << endl;
	return 0;
}
