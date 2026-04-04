#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
		for (int right = nums.size() - 1; left < right;) {
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else --right;
        }
        return nums[left];
    }
};

int main()
{
	Solution s;
	vector<int> nums1 = {1, 3, 5};
    cout << s.findMin(nums1) << endl;
	vector<int> nums2 = {2, 2, 2, 0, 1};
    cout << s.findMin(nums2) << endl;
	return 0;
}
