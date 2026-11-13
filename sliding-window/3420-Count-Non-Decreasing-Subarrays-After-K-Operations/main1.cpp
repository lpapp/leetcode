#include <cassert>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long res = 0, cost = 0;
        deque<int> window;
        for (int n = nums.size(), left = n - 1, right = left; left >= 0; --left) {
            while (!window.empty() && nums[window.front()] <= nums[left]) {
                const int front = window.front(); window.pop_front();
                const int end = window.empty() ? right : window.front() - 1;
                cost += 1LL * (nums[left] - nums[front]) * (end - front + 1);
            }
            window.push_front(left);
            while (cost > k) {
                cost -= nums[window.back()] - nums[right];
                if (window.back() == right) window.pop_back();
                --right;
            }
            res += right - left + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {6, 3, 1, 2, 4, 4};
    assert(s.countNonDecreasingSubarrays(nums1, 7) == 17);
    vector<int> nums2 = {6, 3, 1, 3, 6};
    assert(s.countNonDecreasingSubarrays(nums2, 4) == 12);
    return 0;
}
