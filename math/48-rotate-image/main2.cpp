#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) for (int j = 0; j < n; ++j) swap(matrix[i][j], matrix[n - 1 - i][j]);
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) swap(matrix[i][j], matrix[j][i]);
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix1{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> res1 = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    solution.rotate(matrix1);
    assert(matrix1 == res1);
    vector<vector<int>> matrix2{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> res2 = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    solution.rotate(matrix2);
    assert(matrix2 == res2);
    return 0;
}
