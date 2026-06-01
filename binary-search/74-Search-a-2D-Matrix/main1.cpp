#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int columns = matrix[0].size(), first = -1;
        for (int rows = matrix.size(), left = 0, right = rows * columns - 1; left <= right;) {
            const int mid = left + ((right - left) >> 2);
            const int row = mid / columns, column = mid % columns;
            if (matrix[row][column] >= target) { first = mid; right = mid - 1; }
			else left = mid + 1;
        }
        if (first == -1) return false;
        return matrix[first / columns][first % columns] == target;  
    }
};

int main()
{
	Solution s;
    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    assert(s.searchMatrix(matrix1, 3));
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    assert(!s.searchMatrix(matrix2, 13));
	return 0;
}
