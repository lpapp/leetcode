#include <cassert>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];
        const long long NEG_INF = LLONG_MIN / 2;
        vector<long long> prev(n + 1, 0);
        long long res = NEG_INF;
        for (int j = 1; j <= m; ++j) {
            vector<long long> curr(n + 1, NEG_INF);
            deque<int> dq;
            for (int i = 1; i <= n; ++i) {
                int newStart = i - l;
                if (newStart >= 0 && prev[newStart] != NEG_INF) { long long val = prev[newStart] - prefix[newStart]; while (!dq.empty() && prev[dq.back()] - prefix[dq.back()] <= val) dq.pop_back(); dq.push_back(newStart); }
                while (!dq.empty() && dq.front() < i - r) dq.pop_front();
                curr[i] = curr[i - 1];
                if (!dq.empty()) { long long best = prev[dq.front()] - prefix[dq.front()] + prefix[i]; curr[i] = max(curr[i], best); }
            }
            for (int i = 0; i <= n; ++i) res = max(res, curr[i]);
            prev = std::move(curr);
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {4, 1, -5, 2};
    assert(s.maximumSum(nums1, 2, 1, 3) == 7);
    vector<int> nums2 = {1, 0, 3, 4};
    assert(s.maximumSum(nums2, 2, 1, 2) == 8);
    vector<int> nums3 = {-1, 7, -4};
    assert(s.maximumSum(nums3, 1, 2, 3) == 6);
    vector<int> nums4 = {-3, -4, -1};
    assert(s.maximumSum(nums4, 2, 1, 2) == -1);
	return 0;
}
