#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        for (const int num : nums) if (!result || num != nums[result - 1]) nums[result++] = num;
        return result;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {1, 1, 2};
    cout << s.removeDuplicates(nums1) << endl;
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(nums2) << endl;
	return 0;
}
