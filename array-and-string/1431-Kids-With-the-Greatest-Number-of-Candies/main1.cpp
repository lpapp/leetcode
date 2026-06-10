#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    	int maxCandy = ranges::max(candies);
      	vector<bool> res(candies.size());
      	for (int i = 0, n = candies.size(); i < n; ++i) res[i] = candies[i] + extraCandies >= maxCandy;
      	return res;
    }
};

int main() {
    Solution s;
	vector<int> candies1 = {2, 3, 5, 1, 3};
	vector<bool> res1 = {true, true, true, false, true};
	assert(s.kidsWithCandies(candies1, 3) == res1);
	vector<int> candies2 = {4, 2, 1, 1, 2};
	vector<bool> res2 = {true, false, false, false, false};
	assert(s.kidsWithCandies(candies2, 1) == res2);
	vector<int> candies3 = {12, 1, 12};
	vector<bool> res3 = {true, false, true};
	assert(s.kidsWithCandies(candies3, 10) == res3);
    return 0;
}
