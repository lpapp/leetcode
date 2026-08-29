#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    void radixSortByValue(vector<int>& idx, const vector<int>& nums) {
        vector<int> buf(idx.size());
        for (int shift = 0; shift < 32; shift += 8) {
            int count[257] = {};
            for (const int i : idx) ++count[((nums[i] >> shift) & 255) + 1];
            for (int b = 0; b < 256; ++b) count[b + 1] += count[b];
            for (const int i : idx) buf[count[(nums[i] >> shift) & 255]++] = i;
            idx.swap(buf);
        }
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n = nums.size();
        vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
        radixSortByValue(idx, nums);
        vector<int> group(n), cursor; cursor.reserve(n);
        for (int k = 0; k < n; ++k) {
            if (!k || nums[idx[k]] - nums[idx[k - 1]] > limit) cursor.push_back(k);
            group[idx[k]] = cursor.size() - 1;
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = nums[idx[cursor[group[i]]++]];
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 5, 3, 9, 8};
    vector<int> res1 = {1, 3, 5, 8, 9};
    assert(s.lexicographicallySmallestArray(nums1, 2) == res1);
    vector<int> nums2 = {1, 7, 6, 18, 2, 1};
    vector<int> res2 = {1, 6, 7, 18, 1, 2};
    assert(s.lexicographicallySmallestArray(nums2, 3) == res2);
    vector<int> nums3 = {1, 7, 28, 19, 10};
    vector<int> res3 = {1, 7, 28, 19, 10};
    assert(s.lexicographicallySmallestArray(nums3, 3) == res3);
    return 0;
}
