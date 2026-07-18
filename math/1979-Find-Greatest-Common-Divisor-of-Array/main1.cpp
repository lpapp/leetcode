#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        const auto [mn, mx] = ranges::minmax(nums);
        return gcd(mn, mx);
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 5, 6, 9, 10};
    assert(s.findGCD(nums1));
    vector<int> nums2 = {7, 5, 6, 8, 3};
    assert(s.findGCD(nums2));
    vector<int> nums3 = {3, 3};
    assert(s.findGCD(nums3));
    return 0;
}
