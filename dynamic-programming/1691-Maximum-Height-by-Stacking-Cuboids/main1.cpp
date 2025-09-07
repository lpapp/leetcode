#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids) sort(cuboid.begin(), cuboid.end());
        sort(cuboids.begin(), cuboids.end());

        const size_t n = cuboids.size();
        vector<int> dp(n);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += cuboids[i][2];
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
	Solution s;
    vector<vector<int>> input1 = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
	cout << s.maxHeight(input1) << endl;

    vector<vector<int>> input2 = {{38, 25, 45}, {76, 35, 3}};
	cout << s.maxHeight(input2) << endl;

    vector<vector<int>> input3 = {{7, 11, 17}, {7, 17, 11}, {11, 7, 17}, {11, 17, 7}, {17, 7, 11}, {17, 11, 7}};
	cout << s.maxHeight(input3) << endl;
	return 0;
}
