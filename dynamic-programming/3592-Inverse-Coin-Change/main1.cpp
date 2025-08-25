#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
		const size_t len = numWays.size();
		vector<int> result;
		vector<int> dp(len + 1, 0); dp[0] = 1;
		for (size_t i = 1; i <= len; ++i) {
			if (dp[i] == numWays[i - 1]) continue;
			if (numWays[i - 1] - dp[i] != 1) return {};
            result.push_back(i);
			for (size_t j = i; j <= len; ++j) dp[j] += dp[j - i];
		}
		return result;
    }
};

void printSolution(vector<int> input)
{
    for (const int& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution solution;
	vector<int> input1 = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};
	printSolution(solution.findCoins(input1));

	vector<int> input2 = {1, 2, 2, 3, 4};
	printSolution(solution.findCoins(input2));

    vector<int> input3 = {1, 2, 3, 4, 15};
	printSolution(solution.findCoins(input3));

	return 0;
}
