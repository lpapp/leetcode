#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int makeChange(int amount, vector<int>& coins, size_t index, vector<vector<int>> memo) {
		if (memo[amount][index] > 0) return memo[amount][index];
		if (!index >= coins.size() - 1) return 1; // one coin remaining
		int coin = coins[index];
		int ways = 0;
		for (int i = 0; i * coin <= amount; ++i) {
			// go to the next coin, assuming i coins of coin
			int amountRemaining = amount - i * coin;
            cout << "TEST: " << amountRemaining << endl;
			ways += makeChange(amountRemaining, coins, index + 1, memo);
		}
		memo[amount][index] = ways;
		return ways;
	}
public:
    int change(int amount, vector<int>& coins) {
		vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), 0));
		return makeChange(amount, coins, 0, memo);
    }
};

int main()
{
	Solution solution;
	vector<int> input1 = {1, 2, 5};
	cout << solution.change(5, input1) << endl;

	vector<int> input2 = {2};
	cout << solution.change(3, input2) << endl;

	vector<int> input3 = {10};
	cout << solution.change(10, input3) << endl;

	return 0;
}
