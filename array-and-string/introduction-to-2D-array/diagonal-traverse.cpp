#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      const size_t rows = mat.size(), columns = mat[0].size();                  
      vector<int> diagonalOrder; diagonalOrder.reserve(rows * columns);         
      for (size_t row = 0, column = 0, upwards = 1; row < rows and column < columns;) {
        diagonalOrder.push_back(mat[row][column]);                              
        if (upwards) {                                                          
          if (column == (columns - 1)) { ++row; upwards = 0; }                  
          else if (!row) { ++column; upwards = 0; }                             
          else { --row; ++column; }                                             
        } else {                                                                
          if (row == (rows - 1)) { ++column; upwards = 1; }                     
          else if (!column) { ++row; upwards = 1; }                             
          else { ++row; --column; }                                             
        }                                                                       
      }                                                                         
      return diagonalOrder;
    }
};

void test(vector<vector<int>>& mat)
{
  Solution s;

  cout << "[";
  for (const int e : s.findDiagonalOrder(mat)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  vector<vector<int>> A1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  cout << "[[1,2,3],[4,5,6],[7,8,9]] => [1,2,4,7,5,3,6,8,9]: ";
  test(A1);

  vector<vector<int>> A2{{1, 2}, {3, 4}};
  cout << "[[1,2],[3,4]] => [1,2,3,4]: ";
  test(A2);

  vector<vector<int>> A3{{-100000}};
  cout << "[-100000] => [-100000]: ";
  test(A3);

  return 0;
}
