#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), mx = 0, sum = 0;
        for (const int num : nums) { mx = max(mx, num); sum += num; }
        return mx * n - sum;       
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 1, 3};
    assert(s.minMoves(nums1) == 3);
    vector<int> nums2 = {4, 4, 5};
    assert(s.minMoves(nums2) == 2);
    return 0;
}
