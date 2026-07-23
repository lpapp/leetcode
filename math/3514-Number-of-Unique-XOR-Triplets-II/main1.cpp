#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> pairXor(2048, false);
        for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) pairXor[nums[i] ^ nums[j]] = true;
        vector<bool> tripXor(2048, false);
        for (int x = 0; x < 2048; ++x) {
            if (!pairXor[x]) continue;
            for (int k = 0; k < n; ++k) tripXor[x ^ nums[k]] = true;
        }
        int res = 0;
        for (int x = 0; x < 2048; ++x) res += tripXor[x];
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3};
    assert(s.uniqueXorTriplets(nums1) == 2);
    vector<int> nums2 = {6, 7, 8, 9};
    assert(s.uniqueXorTriplets(nums2) == 4);
    return 0;
}
