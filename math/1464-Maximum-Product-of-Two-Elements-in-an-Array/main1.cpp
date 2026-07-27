#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (const int num : nums) {
            if (num > max1) { max2 = max1; max1 = num; }
            else if (num > max2) max2 = num;
        }
        return (max1 - 1) * (max2 - 1);       
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 4, 5, 2};
    assert(s.maxProduct(nums1) == 12);
    vector<int> nums2 = {1, 5, 4, 5};
    assert(s.maxProduct(nums2) == 16);
    vector<int> nums3 = {3, 7};
    assert(s.maxProduct(nums3) == 12);
    return 0;
}
