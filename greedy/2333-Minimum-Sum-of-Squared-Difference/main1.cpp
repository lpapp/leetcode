#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int length = nums1.size(), maxDiff = 0;
        vector<int> diffs(length);
        for (int i = 0; i < length; ++i) maxDiff = max(maxDiff, diffs[i] = abs(nums1[i] - nums2[i]));
        vector<int> cnt(maxDiff + 1, 0);
        long long budget = (long long)k1 + k2, totalSum = 0;
        for (const int diff : diffs) { ++cnt[diff]; totalSum += diff; }
        if (totalSum <= budget) return 0;
        int level;
        for (level = maxDiff; level > 0 && budget >= cnt[level]; --level) {
            budget -= cnt[level];
            cnt[level - 1] += cnt[level];
            cnt[level] = 0;
        }
        long long shaved = min(budget, (long long)cnt[level]), res = shaved * (level - 1) * (level - 1) + (cnt[level] - shaved) * (long long)level * level;
        for (int i = 0; i < level; ++i) res += (long long)i * i * cnt[i];
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums11 = {1, 2, 3, 4};
    vector<int> nums12 = {2, 10, 20, 19};
    assert(s.minSumSquareDiff(nums11, nums12, 0, 0) == 579);
    vector<int> nums21 = {1, 4, 10, 12};
    vector<int> nums22 = {5, 8, 6, 9};
    assert(s.minSumSquareDiff(nums21, nums22, 1, 1) == 43);
    return 0;
}
