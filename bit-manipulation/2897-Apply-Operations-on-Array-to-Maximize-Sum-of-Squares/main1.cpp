#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD = 1'000'000'007, bitCount[31] = {};
        for (const int num : nums) for (int bitPos = 0; bitPos < 31; ++bitPos) if (num >> bitPos & 1) ++bitCount[bitPos];
        vector<long long> result(k);
        for (int bitPos = 0; bitPos < 31; ++bitPos) for (int t = 0; t < min(k, bitCount[bitPos]); ++t) result[t] |= 1LL << bitPos;
        long long answer = 0;
        for (const long long num : result) answer = (answer + num * num) % MOD;
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 6, 5, 8};
    assert(s.maxSum(nums1, 2) == 261);
    vector<int> nums2 = {4, 5, 4, 7};
    assert(s.maxSum(nums2, 3) == 90);
    return 0;
}
