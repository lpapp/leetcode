#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component; component.reserve(n); component.push_back(0);
        for (int i = 1, id = 0; i < n; ++i) { if (nums[i] - nums[i - 1] > maxDiff) ++id; component.push_back(id); }
        vector<bool> res; res.reserve(queries.size());
        for (const vector<int>& q : queries) res.push_back(component[q[0]] == component[q[1]]);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<vector<int>> queries1 = {{0, 0}, {0, 1}}; 
    vector<bool> res1 = {true, false};
    assert(s.pathExistenceQueries(2, nums1, 1, queries1) == res1);

    vector<int> nums2 = {2, 5, 6, 8};
    vector<vector<int>> queries2 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}}; 
    vector<bool> res2 = {false, false, true, true};
    assert(s.pathExistenceQueries(4, nums2, 2, queries2) == res2);
    return 0;
}
