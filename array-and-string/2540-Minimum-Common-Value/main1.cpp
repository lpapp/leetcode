#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int s1 = nums1.size(), s2 = nums2.size(), i = 0, j = 0; i < s1 && j < s2; nums1[i] < nums2[j] ? ++i : ++j) { if (nums1[i] == nums2[j]) return nums1[i]; }
        return -1;
    }
};

int main()
{
	Solution s;
    vector<int> nums11 = {1, 2, 3};
    vector<int> nums12 = {2, 4};
    assert(s.getCommon(nums11, nums12) == 2);
    vector<int> nums21 = {1, 2, 3, 6};
    vector<int> nums22 = {2, 3, 4, 5};
    assert(s.getCommon(nums21, nums22) == 2);
    vector<int> nums31 = {1, 3, 5};
    vector<int> nums32 = {2, 4, 6};
    assert(s.getCommon(nums31, nums32) == -1);
	return 0;
}
