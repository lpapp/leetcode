#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1, j = n - 1, k = m + n - 1; j >= 0; --k) nums1[k] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];      
    }
};

int main()
{
    Solution s;
    vector<int> nums11 = {1, 2, 3, 0, 0, 0};
    vector<int> nums12 = {2, 5, 6};
    vector<int> res1 = {1, 2, 2, 3, 5, 6};
    s.merge(nums11, 3, nums12, 3);
    assert(nums11 == res1);
    vector<int> nums21 = {1};
    vector<int> nums22 = {};
    vector<int> res2 = {1};
    s.merge(nums21, 1, nums22, 0);
    assert(nums21 == res2);
    vector<int> nums31 = {0};
    vector<int> nums32 = {1};
    vector<int> res3 = {1};
    s.merge(nums31, 0, nums32, 1);
    assert(nums31 == res3);
    return 0;
}
