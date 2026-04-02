#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;
        for (int left = 0, right = nums.size() - 1; left <= right; ) {
            const int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) { result = mid; right = mid - 1; }
            else left = mid + 1;
        }
        if (result != -1 && nums[result] == target) return result;
        return -1;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    cout << s.search(nums1, 9) << endl;
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    cout << s.search(nums2, 2) << endl;
    vector<int> nums3 = {5};
    cout << s.search(nums3, 5) << endl;
	return 0;
}
