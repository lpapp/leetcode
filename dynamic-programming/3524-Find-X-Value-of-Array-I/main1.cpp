#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0);
        for (vector<long long> dp(k, 0); const int num : nums) {
            const int m = num % k;
            vector<long long> ndp(k, 0);
            for (int r = 0; r < k; ++r) if (dp[r]) ndp[(r * m) % k] += dp[r];
            ++ndp[m];
            for (int r = 0; r < k; ++r) res[r] += ndp[r], dp[r] = ndp[r];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<long long> res1 = {9, 2, 4};
    assert(s.resultArray(nums1, 3) == res1);
    vector<int> nums2 = {1, 2, 4, 8, 16, 32};
    vector<long long> res2 = {18, 1, 2, 0};
    assert(s.resultArray(nums2, 4) == res2);
    vector<int> nums3 = {1, 1, 2, 1, 1};
    vector<long long> res3 = {9, 6};
    assert(s.resultArray(nums3, 2) == res3);
    return 0;
}
