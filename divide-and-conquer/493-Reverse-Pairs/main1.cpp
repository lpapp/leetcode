#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    vector<int> tmp;
    int mergeCount(vector<int>& nums, int lo, int hi) {
        if (hi - lo <= 1) return 0;
        int mid = (lo + hi) / 2, res = mergeCount(nums, lo, mid) + mergeCount(nums, mid, hi), j = mid;
        for (int i = lo; i < mid; res += j - mid, ++i) while (j < hi && nums[i] > 2LL * nums[j]) ++j;
        merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + mid, nums.begin() + hi, tmp.begin());
        copy(tmp.cbegin(), tmp.cbegin() + (hi - lo), nums.begin() + lo);
        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        tmp.resize(nums.size());
        return mergeCount(nums, 0, nums.size());
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3, 2, 3, 1};
    assert(s.reversePairs(nums1) == 2);
    vector<int> nums2 = {2, 4, 3, 5, 1};
    assert(s.reversePairs(nums2) == 3);
    return 0;
}
