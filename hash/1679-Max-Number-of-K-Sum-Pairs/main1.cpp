#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int res = 0;
        for (const int num : nums) {
            const int comp = k - num;
            if (hash[comp] > 0) { --hash[comp]; ++res; }
            else ++hash[num];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4};
    assert(s.maxOperations(nums1, 5) == 2);
    vector<int> nums2 = {3, 1, 3, 4, 3};
    assert(s.maxOperations(nums2, 6) == 1);
    return 0;
}
