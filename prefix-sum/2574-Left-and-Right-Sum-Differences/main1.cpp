#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left = 0, right = accumulate(nums.cbegin(), nums.cend(), 0);
        vector<int> res;
        for (const int num : nums) {
            right -= num;
            res.push_back(abs(left - right));
            left += num;
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {10, 4, 8, 3};
    vector<int> res1 = {15, 1, 11, 22};
    assert(s.leftRightDifference(nums1) == res1);
    vector<int> nums2 = {1};
    vector<int> res2 = {0};
    assert(s.leftRightDifference(nums2) == res2);
	return 0;
}
