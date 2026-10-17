#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    static int digitSum(int number) {
        int res = 0;
        for (; number > 0; number /= 10) res += number % 10;
        return res;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), cycles = 0;
        vector<int> keys(n), order(n), perm(n), visited(n, 0);
        for (int i = 0; i < n; ++i) keys[i] = digitSum(nums[i]);
        iota(order.begin(), order.end(), 0);
        ranges::sort(order, [&](int a, int b) { return keys[a] != keys[b] ? keys[a] < keys[b] : nums[a] < nums[b]; });
        for (int rank = 0; rank < n; ++rank) perm[order[rank]] = rank;
        for (int i = 0; i < n; ++i) if (!visited[i]) { ++cycles; for (int j = i; !visited[j]; j = perm[j]) visited[j] = 1; }
        return n - cycles;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {37, 100};
    assert(s.minSwaps(nums1) == 1);
    vector<int> nums2 = {22, 14, 33, 7};
    assert(s.minSwaps(nums2) == 0);
    vector<int> nums3 = {18, 43, 34, 16};
    assert(s.minSwaps(nums3) == 2);
    return 0;
}
