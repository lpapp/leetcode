#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            bool seen[101] = {};
            for (int j = i, distinct = 0; j < n; res += distinct * distinct, ++j) if (!seen[nums[j]]) seen[nums[j]] = true, ++distinct;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 1};
    assert(s.sumCounts(nums1) == 15);
    vector<int> nums2 = {1, 1};
    assert(s.sumCounts(nums2) == 3);
    return 0;
}
