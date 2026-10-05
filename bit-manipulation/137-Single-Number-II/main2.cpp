#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int num : nums) count += ((num >> i) & 1);
            res |= ((count % 3) << i);
        }
        return res;       
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 2, 3, 2};
    assert(s.singleNumber(nums1) == 3);
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    assert(s.singleNumber(nums2) == 99);
    return 0;
}
