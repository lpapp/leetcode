#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int m = nums1.size(), n = nums2.size();
        vector<vector<int>> res;
        auto comparator = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> minHeap(comparator);
        for (int i = 0; i < min(k, m); i++) minHeap.emplace(i, 0);
        while (k-- > 0 && !minHeap.empty()) {
            auto [i, j] = minHeap.top(); minHeap.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < n) minHeap.emplace(i, j + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums11 = {1, 7, 11};
    vector<int> nums12 = {2, 4, 6};
	vector<vector<int>> res1 = {{1, 2}, {1, 4}, {1, 6}};
    assert(s.kSmallestPairs(nums11, nums12, 3) == res1);
    vector<int> nums21 = {1, 1, 2};
    vector<int> nums22 = {1, 2, 3};
	vector<vector<int>> res2 = {{1, 1}, {1, 1}};
    assert(s.kSmallestPairs(nums21, nums22, 2) == res2);
    return 0;
}
