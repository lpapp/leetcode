#include <algorithm>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        constexpr long long MOD = 1'000'000'007;
        const int n = nums.size();
        set<int> ks;
        for (const int num : nums) {
            for (int d = 2; static_cast<long long>(d) * d <= num; ++d) if (!(num % d)) { ks.insert(d); ks.insert(num / d); }
            if (num > 1) ks.insert(num);
        }
        long long bestDiff = LLONG_MIN;
        int bestK = INT_MAX;
        for (const int k : ks) {
            long long cur = 0, maxSub = LLONG_MIN;
            for (int i = 0; i < n; ++i) {
                long long v = (!(nums[i] % k)) ? nums[i] : -nums[i];
                cur = max(v, cur + v);
                maxSub = max(maxSub, cur);
            }
            if (maxSub > bestDiff || (maxSub == bestDiff && k < bestK)) {
                bestDiff = maxSub;
                bestK = k;
            }
        }
        int freeK = 2;
        while (ks.contains(freeK)) ++freeK;
        long long freeDiff = -static_cast<long long>(ranges::min(nums));
        if (freeDiff > bestDiff || (freeDiff == bestDiff && freeK < bestK)) {
            bestDiff = freeDiff;
            bestK = freeK;
        }
        long long res = (bestDiff % MOD) * (bestK % MOD) % MOD;
        return static_cast<int>((res + MOD) % MOD);
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 4, 6, 8};
    assert(s.divisibleGame(nums1) == 36);
    vector<int> nums2 = {2, 1, 2};
    assert(s.divisibleGame(nums2) == 6);
    vector<int> nums3 = {1};
    assert(s.divisibleGame(nums3) == 1000000005);
    return 0;
}
