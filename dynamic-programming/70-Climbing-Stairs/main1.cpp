#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int countWays(int n, vector<int> memo) {
		if (n < 0) return 0;
		else if (!n) return 1;
		else if (memo[n] > -1) return memo[n];

		memo[n] = countWays(n-1, memo) + countWays(n - 2, memo);
		return memo[n];
	}
public:
    int climbStairs(int n) {
		vector<int> memo(n+1, -1);
		return countWays(n, memo);
    }
};

int main()
{
	Solution solution;
	cout << solution.climbStairs(2) << endl;
	cout << solution.climbStairs(3) << endl;
	cout << solution.climbStairs(4) << endl;
	return 0;
}
