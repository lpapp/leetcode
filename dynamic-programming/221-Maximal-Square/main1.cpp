#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
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
	vector<vector<char>> matrix2 = {{'0', '1'}, {'1', '0'}};
	assert(s.maximalSquare(matrix2) == 1);
	vector<vector<char>> matrix2 = {{'0'}};
	assert(!s.maximalSquare(matrix2));
	return 0;
}
