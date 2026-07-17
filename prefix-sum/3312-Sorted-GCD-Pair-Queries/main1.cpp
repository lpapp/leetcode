#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        const int mx = ranges::max(nums);
        vector<int> cnt(mx + 1);
        for (const int num : nums) ++cnt[num];
        vector<long long> gcd_cnt(mx + 1);
        for (int g = mx; g >= 1; --g) {
            long long multiples = 0;
            for (int m = g; m <= mx; m += g) { multiples += cnt[m]; gcd_cnt[g] -= gcd_cnt[m]; }
            gcd_cnt[g] += multiples * (multiples - 1) / 2;
        }
        for (int i = 2; i <= mx; ++i) gcd_cnt[i] += gcd_cnt[i - 1];
        vector<int> res;
        res.reserve(queries.size());
        for (const long long q : queries) res.push_back(upper_bound(gcd_cnt.begin(), gcd_cnt.end(), q) - gcd_cnt.begin());
        return res;        
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 3, 4};
    vector<long long> queries1 = {0, 2, 2};
    vector<int> res1 = {1, 2, 2};
    assert(s.gcdValues(nums1, queries1) == res1);

    vector<int> nums2 = {4, 4, 2, 1};
    vector<long long> queries2 = {5, 3, 1, 0};
    vector<int> res2 = {4, 2, 1, 1};
    assert(s.gcdValues(nums2, queries2) == res2);

    vector<int> nums3 = {2, 2};
    vector<long long> queries3 = {0, 0};
    vector<int> res3 = {2, 2};
    assert(s.gcdValues(nums3, queries3) == res3);
    return 0;
}
