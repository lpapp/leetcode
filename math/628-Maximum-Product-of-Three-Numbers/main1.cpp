#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for (const int num : nums) {
            if (num > max1) { max3 = max2; max2 = max1; max1 = num; }
            else if (num > max2) { max3 = max2; max2 = num; }
            else if (num > max3) max3 = num;
            if (num < min1) { min2 = min1; min1 = num; }
            else if (num < min2) min2 = num;
        }
        return max(max1 * max2 * max3, max1 * min1 * min2);   
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    assert(s.maximumProduct(nums1) == 6);
    vector<int> nums2 = {1, 2, 3, 4};
    assert(s.maximumProduct(nums2) == 24);
    vector<int> nums3 = {-1, -2, -3};
    assert(s.maximumProduct(nums3) == -6);
    return 0;
}
