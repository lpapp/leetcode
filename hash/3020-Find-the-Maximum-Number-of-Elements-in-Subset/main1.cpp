#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
    	unordered_map<long long, int> hash;
    	for (const int num : nums) ++hash[num];
    	int res = hash.contains(1) ? hash[1] - (hash[1] % 2 == 0) : 0;
    	hash.erase(1);
    	for (const auto& [base, freq] : hash) {
    	    int len = 0;
    	    long long cur = base;
    	    while (hash[cur] > 1) { len += 2; cur *= cur; }
    	    len += hash[cur] ? 1 : -1;
    	    res = max(res, len);
    	}
    	return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {5, 4, 1, 2, 2};
    assert(s.maximumLength(nums1) == 3);
    vector<int> nums2 = {1, 3, 2, 4};
    assert(s.maximumLength(nums2) == 1);
    return 0;
}
