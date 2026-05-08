#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int maxNum = ranges::max(nums);
        vector<bool> is_prime(maxNum + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= maxNum; ++i) if (is_prime[i]) for (int j = i * i; j <= maxNum; j += i) is_prime[j] = false;
        unordered_map<int, vector<int>> bucket;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            for (int p = 2; p * p <= v; ++p) {
                if (!(v % p)) {
                    bucket[p].push_back(i);
                    while (!(v % p)) v /= p;
                }
            }
            if (v > 1) bucket[v].push_back(i);
        }
        vector<int> dist(n, -1);
        queue<int> q({0});
        dist[0] = 0;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            int d = dist[i] + 1;
            for (int ni : {i - 1, i + 1}) {
                if (ni >= 0 && ni < n && dist[ni] == -1) {
                    dist[ni] = d;
                    if (ni == n - 1) return d;
                    q.push(ni);
                }
            }
            if (is_prime[nums[i]]) {
                int p = nums[i];
                if (bucket.contains(p)) {
                    for (int j : bucket[p]) {
                        if (dist[j] == -1) {
                            dist[j] = d;
                            if (j == n - 1) return d;
                            q.push(j);
                        }
                    }
                    bucket.erase(p);
                }
            }
        }
        return dist[n - 1];
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 4, 6};
    assert(s.minJumps(nums1) == 2);
    vector<int> nums2 = {2, 3, 4, 7, 9};
    assert(s.minJumps(nums2) == 2);
    vector<int> nums3 = {4, 6, 5, 8};
    assert(s.minJumps(nums3) == 3);
    vector<int> nums4 = {7, 5, 7};
    assert(s.minJumps(nums4) == 1);
    return 0;
}
