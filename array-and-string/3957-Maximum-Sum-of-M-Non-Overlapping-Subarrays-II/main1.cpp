#include <cassert>
#include <deque>
#include <vector>

using namespace std;

class Solution {
    pair<long long, int> check(vector<long long>& prefix, int n, int l, int r, long long penalty) {
        vector<long long> dpVal(n + 1, 0);
        vector<int> dpCnt(n + 1, 0);
        deque<int> dq;
        for (int i = 1; i <= n; ++i) {
            int newStart = i - l;
            if (newStart >= 0) {
                long long nval = dpVal[newStart] - prefix[newStart];
                while (!dq.empty()) {
                    int b = dq.back();
                    long long bval = dpVal[b] - prefix[b];
                    if (bval < nval || (bval == nval && dpCnt[b]< dpCnt[newStart])) dq.pop_back();
                    else break;
                }
                dq.push_back(newStart);
            }
            while (!dq.empty() && dq.front() < i - r) dq.pop_front();
            dpVal[i] = dpVal[i - 1];
            dpCnt[i] = dpCnt[i - 1];
            if (!dq.empty()) {
                int f = dq.front();
                long long candidate = dpVal[f] + prefix[i] - prefix[f] - penalty;
                int candidateCnt = dpCnt[f] + 1;
                if (candidate > dpVal[i] || (candidate == dpVal[i] && candidateCnt > dpCnt[i])) {
                    dpVal[i] = candidate;
                    dpCnt[i] = candidateCnt;
                }
            }
        }
        return {dpVal[n], dpCnt[n]};
    }
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];
        long long bestSingle = LLONG_MIN;
        {
            deque<int> dq;
            for (int i = 1; i <= n; ++i) {
                int ns = i - l;
                if (ns >= 0) {
                    while (!dq.empty() && prefix[dq.back()] >= prefix[ns]) dq.pop_back();
                    dq.push_back(ns);
                }
                while (!dq.empty() && dq.front() < i - r) dq.pop_front();
                if (!dq.empty()) bestSingle = max(bestSingle, prefix[i] - prefix[dq.front()]);
            }
        }
        long long lo = 0, hi = 20000000000LL;
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            auto [val, cnt] = check(prefix, n, l, r, mid);
            if (cnt >= m) lo = mid;
            else hi = mid - 1;
        }
        long long ans = bestSingle;
        auto [val, cnt] = check(prefix, n, l, r, lo);
        if (cnt >= 1) ans = max(ans, val + lo * m);
        return ans;
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
