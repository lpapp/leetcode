#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	int res = 0, n = matrix[0].size();
    	vector<int> dp(n + 1, 0);
    	for (int i = 0, m = matrix.size(); i < m; ++i) {
    	    for (int j = 0, prev = 0; j < n; j++) {
    	        int temp = dp[j + 1];
    	        if (matrix[i][j] == '1') { dp[j + 1] = min({dp[j], dp[j + 1], prev}) + 1; res = max(res, dp[j + 1]); }
				else dp[j + 1] = 0;
    	        prev = temp;
    	    }
    	}
    	return res * res;      
    }
};

int main()
{
	Solution s;
    vector<vector<char>> matrix1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    assert(s.maximalSquare(matrix1) == 4);
    vector<vector<char>> matrix2 = {
        {'0', '1'},
        {'1', '0'}
    };
    assert(s.maximalSquare(matrix2) == 1);
    vector<vector<char>> matrix3 = {{'0'}};
    assert(!s.maximalSquare(matrix3));
	return 0;
}
