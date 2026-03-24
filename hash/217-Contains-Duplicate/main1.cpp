#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; ++i) if (nums[i] == nums[i + 1]) return true;
        return false;       
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << s.containsDuplicate(nums1) << endl;
    vector<int> nums2 = {1, 2, 3, 4};
    cout << s.containsDuplicate(nums2) << endl;
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << s.containsDuplicate(nums3) << endl;
	return 0;
}
