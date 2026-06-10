#include <algorithm>
#include <bit>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        const int n = nums.size();
        const int LOG = std::bit_width((unsigned)n);
        
        vector<vector<int>> spMax(LOG, vector<int>(n));
        vector<vector<int>> spMin(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            spMax[0][i] = nums[i];
            spMin[0][i] = nums[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                spMax[j][i] = max(spMax[j-1][i], spMax[j-1][i + (1 << (j-1))]);
                spMin[j][i] = min(spMin[j-1][i], spMin[j-1][i + (1 << (j-1))]);
            }
        }
        
        auto value = [&](int l, int r) -> int {
            int j = std::bit_width((unsigned)(r - l + 1)) - 1;
            int mx = max(spMax[j][l], spMax[j][r - (1 << j) + 1]);
            int mn = min(spMin[j][l], spMin[j][r - (1 << j) + 1]);
            return mx - mn;
        };
        
        priority_queue<tuple<int,int,int>> pq;
        for (int l = 0; l < n; l++) {
            pq.push({value(l, n - 1), l, n - 1});
        }
        
        long long res = 0;
        for (int i = 0; i < k; i++) {
            auto [v, l, r] = pq.top();
            pq.pop();
            res += v;
            if (r > l) {
                pq.push({value(l, r - 1), l, r - 1});
            }
        }
        
        return res;  
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3, 2};
    assert(s.maxTotalValue(nums1, 2) == 4);
    vector<int> nums2 = {4, 2, 5, 1};
    assert(s.maxTotalValue(nums2, 3) == 12);
    return 0;
}
