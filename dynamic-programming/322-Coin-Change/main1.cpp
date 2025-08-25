#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		static constexpr int intMax = numeric_limits<int>::max();
        vector<int> minCoins(amount + 1, intMax);
        minCoins[0] = 0;

        for (const int coin : coins) {
            for (int currentAmount = coin; currentAmount <= amount; ++currentAmount) {
                if (minCoins[currentAmount - coin] != intMax) {
                    minCoins[currentAmount] = min(minCoins[currentAmount], minCoins[currentAmount - coin] + 1);
                }
            }
        }

        return minCoins[amount] == intMax ? -1 : minCoins[amount];
    }
};

int main()
{
	Solution solution;
	vector<int> input1 = {1, 2, 5};
	cout << solution.coinChange(input1, 11) << endl;

	vector<int> input2 = {2};
	cout << solution.coinChange(input2, 3) << endl;

	vector<int> input3 = {1};
	cout << solution.coinChange(input3, 0) << endl;

	return 0;
}
