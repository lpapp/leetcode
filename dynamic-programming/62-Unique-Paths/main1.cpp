#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<size_t> currentRowCounts(n, 1);
        for (int row = 1; row < m; ++row) {
            for (int column = 1; column < n; ++column) currentRowCounts[column] += currentRowCounts[column - 1];
        }
        return currentRowCounts[n - 1];     
    }
};

int main()
{
	Solution solution;
	cout << solution.uniquePaths(3, 7) << endl;
	cout << solution.uniquePaths(3, 2) << endl;
	return 0;
}
