#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
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
