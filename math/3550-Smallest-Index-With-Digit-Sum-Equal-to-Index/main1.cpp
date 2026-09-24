#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int digitSum = 0;
            for (int num = nums[i]; num; num /= 10) digitSum += num % 10;
            if (digitSum == i) return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3, 2};
    assert(s.smallestIndex(nums1) == 2);
    vector<int> nums2 = {1, 10, 11};
    assert(s.smallestIndex(nums2) == 1);
    vector<int> nums3 = {1, 2, 3};
    assert(s.smallestIndex(nums3) == -1);
    return 0;
}
