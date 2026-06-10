#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    	int ans = 0;
    	for (int i = 0, n = tickets.size(); i < n; ++i) ans += min(tickets[i], tickets[k] - (i > k));
    	return ans;
    }
};

int main()
{
	Solution s;
    vector<int> tickets1 = {2, 3, 2};
    assert(s.timeRequiredToBuy(tickets1, 2) == 6);
    vector<int> tickets2 = {5, 1, 1, 1};
    assert(s.timeRequiredToBuy(tickets2, 0) == 8);
	return 0;
}
