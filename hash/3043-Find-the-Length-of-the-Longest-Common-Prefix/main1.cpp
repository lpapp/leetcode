#include <algorithm>
#include <cassert>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> hash;
        for (int num : arr1) for (; num > 0; hash.insert(num), num /= 10);
        int res = 0;
        for (int num : arr2) {
            for (; num > 0; num /= 10) {
                if (hash.contains(num)) { res = max(res, static_cast<int>(log10(num)) + 1); break; }
			}
        }
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> arr11 = {1, 10, 100};
	vector<int> arr12 = {1000};
	assert(s.longestCommonPrefix(arr11, arr12) == 3);
	vector<int> arr21 = {1, 2, 3};
	vector<int> arr22 = {4, 4, 4};
	assert(s.longestCommonPrefix(arr21, arr22) == 0);
	return 0;
}
