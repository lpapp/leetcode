#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    	int res = 0;
    	for (int i = 0, alt = 0, n = gain.size(); i < n; ++i) res = max(res, alt += gain[i]);
    	return res;
    }
};

int main()
{
	Solution s;
    vector<int> gain1 = {-5, 1, 5, 0, -7};
    assert(s.largestAltitude(gain1) == 1);
    vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};
    assert(!s.largestAltitude(gain2));
	return 0;
}
