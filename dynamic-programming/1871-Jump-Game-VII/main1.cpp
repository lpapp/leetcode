#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> pre(n + 1, 0); pre[1] = 1;
        for (int i = 1; i < n; ++i) {
            int l = max(0, i - maxJump), r = i - minJump;
            int reached = s[i] == '0' && l <= r && pre[r + 1] - pre[l] > 0;
            pre[i + 1] = pre[i] + reached;
        }
        return pre[n] - pre[n - 1];
    }
};

int main()
{
	Solution s;
	assert(s.canReach("011010", 2, 3));
	assert(!s.canReach("01101110", 2, 3));
	return 0;
}
