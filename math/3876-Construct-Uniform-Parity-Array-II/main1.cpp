#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (const int num : nums1) if (num & 1) minOdd = min(minOdd, num); else minEven = min(minEven, num);
        return minOdd == INT_MAX || minEven == INT_MAX || minOdd < minEven;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 4, 7};
    assert(s.uniformArray(nums1));
    vector<int> nums2 = {2, 3};
    assert(!s.uniformArray(nums2));
    vector<int> nums3 = {4, 6};
    assert(s.uniformArray(nums3));
    return 0;
}
