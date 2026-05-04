#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k % nums.size());
      reverse(nums.begin() + k % nums.size(), nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7}; 
    vector<int> res1 = {5, 6, 7, 1, 2, 3, 4};
    s.rotate(nums1, 3);
    assert(nums1 == res1);
    vector<int> nums2 = {-1, -100, 3, 99}; 
    vector<int> res2 = {3, 99, -1, -100};
    s.rotate(nums2, 2);
    assert(nums2 == res2);
    return 0;
}
