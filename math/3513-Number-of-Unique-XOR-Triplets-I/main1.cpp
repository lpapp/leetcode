#include <bit>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return n;
        return 1 << (bit_width(static_cast<unsigned>(n)));
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2};
    assert(s.uniqueXorTriplets(nums1) == 2);
    vector<int> nums2 = {3, 1, 2};
    assert(s.uniqueXorTriplets(nums2) == 4);
    return 0;
}
