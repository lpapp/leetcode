#include <cassert>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res, arr2;
        res.reserve(n); arr2.reserve(n);
        res.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; ++i)
            if (res.back() > arr2.back()) res.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        res.insert(res.end(), arr2.begin(), arr2.end());
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 1, 3};
    vector<int> res1 = {2, 3, 1};
    assert(s.resultArray(nums1) == res1);
    vector<int> nums2 = {5, 4, 3, 8};
    vector<int> res2 = {5, 3, 4, 8};
    assert(s.resultArray(nums2) == res2);
    return 0;
}
