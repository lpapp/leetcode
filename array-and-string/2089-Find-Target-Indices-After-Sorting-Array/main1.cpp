#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0, equalCount = 0;
        for (const int num : nums) {
            if (num < target) ++lessCount;
            else if (num == target) ++equalCount;
        }
        vector<int> res; res.reserve(equalCount);
        for (int i = 0; i < equalCount; ++i) res.push_back(lessCount + i);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 5, 2, 3};
    vector<int> res1 = {1, 2};
    assert(s.targetIndices(nums1, 2) == res1);
    vector<int> nums2 = {1, 2, 5, 2, 3};
    vector<int> res2 = {3};
    assert(s.targetIndices(nums2, 3) == res2);
    vector<int> nums3 = {1, 2, 5, 2, 3};
    vector<int> res3 = {4};
    assert(s.targetIndices(nums3, 5) == res3);
    return 0;
}
