#include <algorithm>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

class Solution {
    static vector<long long> windowCosts(const vector<int>& nums, const int x) {
        const int n = nums.size();
        vector<long long> res; res.reserve(n - x + 1);
        multiset<int> low, high;
        long long lowSum = 0, highSum = 0;
        for (int i = 0; i < n; ++i) {
            if (low.empty() || nums[i] <= *low.rbegin()) { low.insert(nums[i]); lowSum += nums[i]; }
            else { high.insert(nums[i]); highSum += nums[i]; }
            if (i >= x) {
                const int out = nums[i - x];
                if (out <= *low.rbegin()) { low.erase(low.find(out)); lowSum -= out; }
                else { high.erase(high.find(out)); highSum -= out; }
            }
            while (low.size() > high.size() + 1) {
                const int value = *low.rbegin();
                low.erase(prev(low.end())); lowSum -= value;
                high.insert(value); highSum += value;
            }
            while (high.size() > low.size()) {
                const int value = *high.begin();
                high.erase(high.begin()); highSum -= value;
                low.insert(value); lowSum += value;
            }
            if (i < x - 1) continue;
            const long long median = *low.rbegin();
            res.push_back(median * (long long)low.size() - lowSum + highSum - median * (long long)high.size());
        }
        return res;
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        const int n = nums.size();
        const vector<long long> cost = windowCosts(nums, x);
        vector<long long> previous(n + 1, 0), current(n + 1);
        for (int count = 1; count <= k; ++count) {
            fill(current.begin(), current.end(), LLONG_MAX / 2);
            for (int i = count * x; i <= n; ++i) current[i] = min(current[i - 1], previous[i - x] + cost[i
 - x]);
            swap(previous, current);
        }
        return previous[n];
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {5, -2, 1, 3, 7, 3, 6, 4, -1};
    assert(s.minOperations(nums1, 3, 2) == 8);
    vector<int> nums2 = {9, -2, -2, -2, 1, 5};
    assert(s.minOperations(nums2, 2, 2) == 3);
    return 0;
}
