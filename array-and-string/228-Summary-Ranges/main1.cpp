#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int start = 0, end = 0, n = nums.size(); start < n; start = end + 1) {
            for (end = start; end + 1 < n && nums[end + 1] == nums[end] + 1; ++end);
            res.emplace_back(start == end ? to_string(nums[start]) : (to_string(nums[start]) + "->" + to_string(nums[end])));
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> res1 = {"0->2", "4->5", "7"};
    assert(s.summaryRanges(nums1) == res1);
    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<string> res2 = {"0", "2->4", "6", "8->9"};
    assert(s.summaryRanges(nums2) == res2);
	return 0;
}
