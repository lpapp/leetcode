#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static vector<int> buildSuffixArray(const vector<int>& nums) {
        const int n = nums.size(), buckets = max(ranges::max(nums), n) + 1;
        vector<int> suffixArray(n), rankOf(nums), shifted(n), nextRankOf(n), count(buckets);
        for (const int num : nums) ++count[num];
        for (int i = 1; i < buckets; ++i) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; --i) suffixArray[--count[rankOf[i]]] = i;
        for (int width = 1; ; width <<= 1) {
            int filled = 0, classes = 0;
            for (int start = max(0, n - width); start < n; ++start) shifted[filled++] = start;
            for (const int start : suffixArray) if (start >= width) shifted[filled++] = start - width;
            ranges::fill(count, 0);
            for (const int value : rankOf) ++count[value];
            for (int i = 1; i < buckets; ++i) count[i] += count[i - 1];
            for (int i = n - 1; i >= 0; --i) suffixArray[--count[rankOf[shifted[i]]]] = shifted[i];
            nextRankOf[suffixArray[0]] = 0;
            for (int i = 1; i < n; ++i) {
                const int previous = suffixArray[i - 1], current = suffixArray[i];
                if (rankOf[previous] != rankOf[current] || (previous + width < n ? rankOf[previous + width] : -1) != (current + width < n ? rankOf[current + width] : -1)) ++classes;
                nextRankOf[current] = classes;
            }
            rankOf.swap(nextRankOf);
            if (classes == n - 1) return suffixArray;
        }
    }
    static vector<int> buildLcp(const vector<int>& nums, const vector<int>& suffixArray) {
        const int n = nums.size();
        vector<int> rankOf(n), res(n + 1);
        for (int i = 0; i < n; ++i) rankOf[suffixArray[i]] = i;
        for (int start = 0, match = 0; start < n; ++start) {
            if (!rankOf[start]) { match = 0; continue; }
            const int previous = suffixArray[rankOf[start] - 1];
            while (start + match < n && previous + match < n && nums[start + match] == nums[previous + match]) ++match;
            res[rankOf[start]] = match;
            if (match) --match;
        }
        return res;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        const int n = nums.size();
        const vector<int> suffixArray = buildSuffixArray(nums), lcp = buildLcp(nums, suffixArray);
        int res = n;
        for (int i = 0; i < n; ++i) {
            const int length = max(lcp[i], lcp[i + 1]) + 1;
            if (suffixArray[i] + length <= n) res = min(res, length);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 3, 3};
    assert(s.smallestUniqueSubarray(nums1) == 3);
    vector<int> nums2 = {2, 1, 2, 3, 3};
    assert(s.smallestUniqueSubarray(nums2) == 1);
    vector<int> nums3 = {1, 1, 2, 2, 1};
    assert(s.smallestUniqueSubarray(nums3) == 2);
    return 0;
}
