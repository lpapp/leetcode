#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow], fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        for (fast = 0;;) {
            slow = nums[slow], fast = nums[fast];
            if (slow == fast) return slow;
        }
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << s.findDuplicate(nums1) << endl;
    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << s.findDuplicate(nums2) << endl;
    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << s.findDuplicate(nums3) << endl;
	return 0;
}
