#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mn = INT_MAX;
        for (int num : nums) sum += num, mn = min(mn, num);
        return sum - (long long)mn * nums.size();       
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    assert(s.minMoves(nums1) == 3);
    vector<int> nums2 = {1, 1, 1};
    assert(s.minMoves(nums2) == 0);
    return 0;
}
