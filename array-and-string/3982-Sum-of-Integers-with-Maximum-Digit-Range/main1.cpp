#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange, res = 0;
        for (int num : nums) {
            int lo = 9, hi = 0;
            for (int x = num; x > 0; x /= 10) {
                int d = x % 10;
                lo = min(lo, d);
                hi = max(hi, d);
            }
            const int range = hi - lo;
            if (range > maxRange) {
                maxRange = range;
                res = num;
            } else if (range == maxRange) {
                res += num;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {5724, 111, 350};
    assert(s.maxDigitRange(nums1) == 6074);
    vector<int> nums2 = {90, 900};
    assert(s.maxDigitRange(nums2) == 990);
    return 0;
}
