#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const size_t columns = matrix[0].size();
        for (const vector<int>& row : matrix) {
            int result = -1;
            for (int left = 0, right = columns - 1; left <= right;) {
                const int mid = left + ((right - left) >> 1);
                if (row[mid] >= target) { result = mid; right = mid - 1; }
				else left = mid + 1;
            }
            if (result != -1 && row[result] == target) return true;
        }
        return false;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << s.searchMatrix(matrix1, 5) << endl;
    vector<vector<int>> matrix2 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << s.searchMatrix(matrix2, 20) << endl;
	return 0;
}
