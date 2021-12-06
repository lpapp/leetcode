#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      const size_t rows = matrix.size(), columns = matrix[0].size();
      vector<int> diagonalOrder; diagonalOrder.reserve(rows * columns);
      for (int row = 0, column = 0, direction = 0, left = 0, right = columns - 1, top = 0, bottom = rows - 1; left <= right and top <= bottom;) {
        diagonalOrder.push_back(matrix[row][column]);
        if (!direction) { if (column == right) { ++row; ++direction; ++top; } else ++column; }
        else if (direction == 1) { if (row == bottom) { --column; ++direction; --right; } else ++row; }
        else if (direction == 2) { if (column == left) { --row; ++direction; --bottom; } else --column; }
        else { if (row == top) { ++column; direction = 0; ++left; } else --row; }
      }
      return diagonalOrder;
    }
};

void test(vector<vector<int>>& matrix)
{
  Solution s;

  cout << "[";
  for (const int e : s.spiralOrder(matrix)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  vector<vector<int>> A1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  cout << "[[1,2,3],[4,5,6],[7,8,9]] => [1,2,3,6,9,8,7,4,5]: ";
  test(A1);

  vector<vector<int>> A2{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  cout << "[[1,2,3,4],[5,6,7,8],[9,10,11,12]] => [1,2,3,4,8,12,11,10,9,5,6,7]: ";
  test(A2);

  vector<vector<int>> A3{{-100}};
  cout << "[-100] => [-100]: ";
  test(A3);

  vector<vector<int>> A4{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
  cout << "[[1,2,3,4,5,6,7,8,9,10]] => [1,2,3,4,5,6,7,8,9,10]: ";
  test(A4);

  vector<vector<int>> A5{{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};
  cout << "[[1],[2],[3],[4],[5],[6],[7],[8],[9],[10]] => [1,2,3,4,5,6,7,8,9,10]: ";
  test(A5);

  // 1 2 3
  // 4 5 6
  // 7 8 9
  // 10 11 12
  // 13 14 15
  // 16 17 18
  // -> 1,2,3,6,9,12,15,18,17,16,13,10,7,4,5,8,11,14

  vector<vector<int>> A6{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
  cout << "[[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15],[16,17,18]] => [1,2,3,6,9,12,15,18,17,16,13,10,7,4,5,8,11,14]: ";
  test(A6);

  return 0;
}
