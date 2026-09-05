#include <array>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<array<int, 2>> tr;
        tr.reserve(nums.size() * 31 + 1);
        tr.push_back({-1, -1});
        for (const int x : nums) {
            int cur = 0;
            for (int i = 30; i >= 0; --i) {
                const int b = (x >> i) & 1;
                if (tr[cur][b] < 0) { tr[cur][b] = tr.size(); tr.push_back({-1, -1}); }
                cur = tr[cur][b];
            }
        }
        int res = 0;
        for (const int x : nums) {
            int cur = 0, cand = 0;
            for (int i = 30; i >= 0; --i) {
                const int b = (x >> i) & 1;
                if (tr[cur][b ^ 1] >= 0) { cand |= 1 << i; cur = tr[cur][b ^ 1]; }
                else cur = tr[cur][b];
            }
            res = max(res, cand);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    assert(s.findMaximumXOR(nums1) == 28);
    vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    assert(s.findMaximumXOR(nums2) == 127);
    return 0;
}
