#include <algorithm>
#include <cassert>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int parent[100001];
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    void unite(int a, int b) { parent[find(a)] = find(b); }
public:
    int largestComponentSize(vector<int>& nums) {
        iota(parent, parent + 100001, 0);
        for (int num : nums) for (int d = 2; d * d <= num; ++d) if (num % d == 0) { unite(num, d); unite(num, num / d); }
        unordered_map<int, int> count;
        int res = 0;
        for (const int num : nums) res = max(res, ++count[find(num)]);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {4, 6, 15, 35};
    assert(s.largestComponentSize(nums1) == 4);
    vector<int> nums2 = {20, 50, 9, 63};
    assert(s.largestComponentSize(nums2) == 2);
    vector<int> nums3 = {2, 3, 6, 7, 4, 12, 21, 39};
    assert(s.largestComponentSize(nums3) == 8);
    return 0;
}
