#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int result = -1;
        for (int n = nums.size(), left = 0, right = n - 1; left <= right;) {
            const int mid = left + ((right - left) >> 1);
            if (mid == n - 1 || nums[mid] > nums[mid + 1]) { result = mid; right = mid - 1; }
			else left = mid + 1;
        }
        return result; 
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << s.findPeakElement(nums1) << endl;
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << s.findPeakElement(nums2) << endl;
	return 0;
}
