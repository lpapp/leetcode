#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    long long getSum(vector<int>& nums) {
        const int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + nums[i];
        auto rangeSum = [&](int l, int r) { return pre[r + 1] - pre[l]; };
        long long res = ranges::max(nums);
        vector<int> odd(n, 0);
        for (int i = 0, c = 0, r = 0; i < n; ++i) {
            if (i < r) odd[i] = min(r - i, odd[2 * c - i]);
            while (i - odd[i] - 1 >= 0 && i + odd[i] + 1 < n && nums[i - odd[i] - 1] == nums[i + odd[i] + 1]) ++odd[i];
            if (i + odd[i] > r) { c = i; r = i + odd[i]; }
            res = max(res, rangeSum(i - odd[i], i + odd[i]));
        }
        vector<int> even(n, 0);
        for (int i = 1, c = 0, r = 0; i < n; ++i) {
            if (i < r) even[i] = min(r - i, even[2 * c - i]);
            while (i - even[i] - 1 >= 0 && i + even[i] < n && nums[i - even[i] - 1] == nums[i + even[i]]) ++even[i];
            if (i + even[i] > r) { c = i; r = i + even[i]; }
            if (even[i] > 0) res = max(res, rangeSum(i - even[i], i + even[i] - 1));
        }
        return res;
    }
};

int main()
{
    Solution s;
	vector<int> nums1 = {10, 10};
    assert(s.getSum(nums1) == 20);
	vector<int> nums2 = {1, 2, 3, 2, 1, 5, 6};
    assert(s.getSum(nums2) == 9);
	vector<int> nums3 = {7, 1, 2, 1, 7, 3, 4, 3, 4};
    assert(s.getSum(nums3) == 18);
	vector<int> nums4 = {1, 2, 3, 4, 5};
    assert(s.getSum(nums4) == 5);
	vector<int> nums5 = {1000};
    assert(s.getSum(nums5) == 1000);
    return 0;
}
