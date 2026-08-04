#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        const auto [lo, hi] = ranges::minmax(nums);
        vector<bool> present(hi - lo + 1, false);
        for (const int num : nums) present[num - lo] = true;
        vector<int> res;
        for (int i = lo + 1; i < hi; ++i) if (!present[i - lo]) res.push_back(i);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 4, 2, 5};
    vector<int> res1 = {3};
    assert(s.findMissingElements(nums1) == res1);
    vector<int> nums2 = {7, 8, 6, 9};
    vector<int> res2 = {};
    assert(s.findMissingElements(nums2) == res2);
    vector<int> nums3 = {5, 1};
    vector<int> res3 = {2, 3, 4};
    assert(s.findMissingElements(nums3) == res3);
    return 0;
}
