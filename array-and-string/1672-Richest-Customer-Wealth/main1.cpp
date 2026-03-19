#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for (const vector<int>& customerAccounts : accounts) result = max(result, reduce(customerAccounts.cbegin(), customerAccounts.cend()));
        return result;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> accounts1 = {
        { 1, 2, 3 },
        { 3, 2, 1 }
    };
    cout << s.maximumWealth(accounts1) << endl;

    vector<vector<int>> accounts2 = {
        { 1, 5 },
        { 7, 3 },
        { 3, 5 }
    };
    cout << s.maximumWealth(accounts2) << endl;

    vector<vector<int>> accounts3 = {
        { 2, 8, 7 },
        { 7, 1, 3 },
        { 1, 9, 5 }
    };
    cout << s.maximumWealth(accounts3) << endl;
	return 0;
}
