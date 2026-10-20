#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static bool blockIsRotationOfSorted(const vector<int>& nums, const vector<int>& sorted, int start, int k) {
        vector<int> combined; combined.reserve(3 * k + 1);
        for (int i = 0; i < k; ++i) combined.push_back(sorted[start + i]);
        combined.push_back(-1);
        for (int rep = 0; rep < 2; ++rep) for (int i = 0; i < k; ++i) combined.push_back(nums[start + i]);
        const int m = combined.size();
        vector<int> fail(m, 0);
        for (int i = 1, len = 0; i < m; ) {
            if (combined[i] == combined[len]) fail[i++] = ++len;
            else if (len) len = fail[len - 1];
            else fail[i++] = 0;
        }
        for (int i = k + 1; i < m; ++i) if (fail[i] == k) return true;
        return false;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        const int n = nums.size();
        vector<int> sorted = nums; ranges::sort(sorted);
        int res = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k) continue;
            bool ok = true;
            for (int i = 0; i < n && ok; i += k) if (!blockIsRotationOfSorted(nums, sorted, i, k)) ok = false;
            if (ok) res += k;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 1, 2};
    assert(s.sortableIntegers(nums1) == 3);
    vector<int> nums2 = {7, 6, 5};
    assert(s.sortableIntegers(nums2) == 0);
    vector<int> nums3 = {5, 8};
    assert(s.sortableIntegers(nums3) == 3);
    return 0;
}
