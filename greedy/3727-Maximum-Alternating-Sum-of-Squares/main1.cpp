#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int MAXV = 40000, mag = 0;
        vector<int> freq(MAXV + 1);
        for (const int num : nums) ++freq[abs(num)];
        long long n = nums.size(), half = n / 2, subtractCount = 0, answer = 0;
        for (; mag <= MAXV; ++mag) {
            if (!freq[mag]) continue;
            const long long take = min<long long>(freq[mag], half - subtractCount);
            answer -= take * (long long)mag * mag;
            freq[mag] -= (int)take;
            subtractCount += take;
            if (subtractCount == half) break;
        }
        for (; mag <= MAXV; ++mag) if (freq[mag]) answer += (long long)freq[mag] * mag * mag;
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    assert(s.maxAlternatingSum(nums1) == 12);
    vector<int> nums2 = {1, -1, 2, -2, 3, -3};
    assert(s.maxAlternatingSum(nums2) == 16);
    return 0;
}
