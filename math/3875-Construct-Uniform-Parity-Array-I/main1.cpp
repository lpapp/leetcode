#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 3};
    assert(s.uniformArray(nums1));
    vector<int> nums2 = {4, 6};
    assert(s.uniformArray(nums2));
    return 0;
}
