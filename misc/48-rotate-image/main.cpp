#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       const size_t matrixSize = matrix.size();
       if (!matrixSize || matrixSize != matrix[0].size()) return;
       for (size_t first = 0, last = matrixSize - 1; first < matrixSize/2; ++first, --last) {
           for (size_t i = first; i < last; ++i) {
               const int offset =  i - first;
               const int top = matrix[first][i]; // save the top

               // left -> top
               matrix[first][i] = matrix[last - offset][first];

               // bottom -> left
               matrix[last - offset][first] = matrix[last][last - offset];

               // right -> bottom
               matrix[last][last - offset] = matrix[i][last];

               // top -> right
               matrix[i][last] = top; // right <- saved top
           }
       }
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix1{{1,2,3},{4,5,6},{7,8,9}};
    solution.rotate(matrix1);
    vector<vector<int>> matrix2{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    solution.rotate(matrix2);
    return 0;
}
