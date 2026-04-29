#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long>> prefix(n, vector<long>(n + 1));
        vector<long> prevIsBigger(n + 1), prevNotBigger(n + 1);
        for (int j = 0; j < n; ++j) for (int i = 0; i < n; ++i) prefix[j][i + 1] = prefix[j][i] + grid[i][j];
        for (int j = 1; j < n; ++j) {
            vector<long> currIsBigger(n + 1), currNotBigger(n + 1);
            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    if (curr > prev) {
                        long score = prefix[j - 1][curr] - prefix[j - 1][prev];
                        currIsBigger[curr] = max(currIsBigger[curr], prevNotBigger[prev] + score);
                        currNotBigger[curr] = max(currNotBigger[curr], prevNotBigger[prev] + score);
                    } else {
                        long score = prefix[j][prev] - prefix[j][curr];
                        currIsBigger[curr] = max(currIsBigger[curr], prevIsBigger[prev] + score);
                        currNotBigger[curr] = max(currNotBigger[curr], prevIsBigger[prev]);
                    }
				}
			}
            prevIsBigger = std::move(currIsBigger);
            prevNotBigger = std::move(currNotBigger);
        }
        return ranges::max(prevIsBigger);
    }
};

int main()
{
	Solution s;
    vector<vector<int>> grid1 = {
        {0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 1, 0, 0, 0},
        {5, 0, 0, 3, 0},
        {0, 0, 0, 0, 2}
    };
    cout << s.maximumScore(grid1) << endl;
    vector<vector<int>> grid2 = {
        {10, 9, 0, 0, 15},
        {7, 1, 0, 8, 0},
        {5, 20, 0, 11, 0},
        {0, 0, 0, 1, 2},
        {8, 12, 1, 10, 3}
    };
    cout << s.maximumScore(grid2) << endl;
	return 0;
}
