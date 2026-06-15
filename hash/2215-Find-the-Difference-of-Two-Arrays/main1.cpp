#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.cbegin(), nums1.cend()), s2(nums2.cbegin(), nums2.cend());
        vector<vector<int>> res(2);
        for (const int v : s1) if (!s2.contains(v)) res[0].push_back(v);
        for (const int v : s2) if (!s1.contains(v)) res[1].push_back(v);
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> nums11 = {1, 2, 3};
	vector<int> nums12 = {2, 4, 6};
    vector<vector<int>> res1 = {
        {1, 3},
        {4, 6}
    };
    vector<vector<int>> r1 = s.findDifference(nums11, nums12);
    sort(r1[0].begin(), r1[0].end());
    sort(r1[1].begin(), r1[1].end());
	assert(r1 == res1);
	vector<int> nums21 = {1, 2, 3, 3};
	vector<int> nums22 = {1, 1, 2, 2};
    vector<vector<int>> res2 = {
        {3},
        {}
    };
    vector<vector<int>> r2 = s.findDifference(nums21, nums22);
    sort(r2[0].begin(), r2[0].end());
    sort(r2[1].begin(), r2[1].end());
	assert(r2 == res2);
	return 0;
}
