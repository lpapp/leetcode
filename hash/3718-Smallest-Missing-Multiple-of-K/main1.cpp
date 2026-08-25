#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool seen[101] = {};
        for (const int num : nums) seen[num] = true;
        for (int m = k; ; m += k) if (m > 100 || !seen[m]) return m;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {8, 2, 3, 4, 6};
    assert(s.missingMultiple(nums1, 2) == 10);
    vector<int> nums2 = {1, 4, 7, 10, 15};
    assert(s.missingMultiple(nums2, 5) == 5);
    return 0;
}
