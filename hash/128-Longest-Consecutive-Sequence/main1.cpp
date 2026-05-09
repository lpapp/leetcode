#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsHashSet(nums.cbegin(), nums.cend());
        int res = 0;
        unordered_map<int, int> lengthsHash;
        for (const int num : nums) {
            int next;
            for (next = num; numsHashSet.count(next); numsHashSet.erase(next++));
            const int length = (next - num) + (lengthsHash.count(next) ? lengthsHash[next] : 0);
            lengthsHash[num] = length;
            res = max(res, lengthsHash[num]);
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    assert(s.longestConsecutive(nums1) == 4);
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    assert(s.longestConsecutive(nums2) == 9);
    vector<int> nums3 = {1, 0, 1, 2};
    assert(s.longestConsecutive(nums3) == 3);
	return 0;
}
