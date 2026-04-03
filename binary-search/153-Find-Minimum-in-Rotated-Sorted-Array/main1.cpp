#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = -1;
        for (int n = nums.size(), left = 0, right = n - 1; left <= right;) {
            const int mid = left + ((right - left) >> 1);
            if (nums[mid] <= nums[n - 1]) { result = mid; right = mid - 1; }
			else left = mid + 1;
        }
        return nums[result];
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << s.findMin(nums1) << endl;
	vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << s.findMin(nums2) << endl;
	vector<int> nums3 = {11, 13, 15, 17};
    cout << s.findMin(nums3) << endl;
	return 0;
}
