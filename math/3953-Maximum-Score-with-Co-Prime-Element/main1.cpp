#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static vector<int> computeMobius(int limit) {
        vector<int> res(limit + 1, 0), sp(limit + 1, 0);
        res[1] = 1;
        for (int i = 2; i <= limit; ++i) if (!sp[i]) for (int j = i; j <= limit; j += i) if (!sp[j]) sp[j] = i;
        for (int i = 2; i <= limit; ++i) { int p = sp[i], prev = i / p; res[i] = (prev % p == 0) ? 0 : -res[prev]; }
        return res;
    }

    static vector<int> computeCoprimeCount(vector<int>& freq, vector<int>& res, int limit) {
        vector<int> F(limit + 1, 0);
        for (int d = 1; d <= limit; ++d) for (int m = d; m <= limit; m += d) F[d] += freq[m];
        vector<int> coprimeCount(limit + 1, 0);
        for (int d = 1; d <= limit; ++d) { if (!res[d]) continue; int val = res[d] * F[d]; for (int v = d; v <= limit; v += d) coprimeCount[v] += val; }
        return coprimeCount;
    }

    static int bestTermForValue(int v, int n, int cc, int fv) {
        if (v > 1 && fv > 0) return 1;
        if (v == 1 && fv > 0) return 0;
        if ((n - cc) - fv > 0) return 0;
        return -1;
    }
public:
    int maxScore(vector<int>& nums, int maxVal) {
        int n = nums.size();
        int limit = max(ranges::max(nums), maxVal);
        vector<int> freq(limit + 1, 0);
        for (int x : nums) freq[x]++;
        vector<int> mobius = computeMobius(limit);
        vector<int> coprimeCount = computeCoprimeCount(freq, mobius, limit);
        int res = INT_MIN;
        for (int v = 1; v <= limit; ++v) { if (v > maxVal && !freq[v]) continue; int cc = coprimeCount[v]; int score = v - n + cc + bestTermForValue(v, n, cc, freq[v]); res = max(res, score); }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {3, 4, 6};
    assert(s.maxScore(nums1, 5) == 4);
    vector<int> nums2 = {1, 2, 3};
    assert(s.maxScore(nums2, 4) == 3);
    vector<int> nums3 = {2, 2};
    assert(s.maxScore(nums3, 1) == 1);
	return 0;
}
