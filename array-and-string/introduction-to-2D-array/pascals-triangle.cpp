#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> pascals_triangle(numRows, vector<int>{1});
      for (int row = 1; row < numRows; ++row) pascals_triangle[row].reserve(row + 1);
      for (int row = 1; row < numRows; pascals_triangle[row].push_back(1), ++row) {
        
        for (int column = 1; column < row; ++column) {
          pascals_triangle[row].push_back(pascals_triangle[row - 1][column - 1] + pascals_triangle[row - 1][column]);
        }
      };
      return pascals_triangle;
    }
};

void test(int numRows)
{
  Solution s;

  cout << "[";
  for (const vector<int>& row : s.generate(numRows)) {
    cout << "[";
    for (const int e : row) cout << e << ",";
    cout << "]";
  }
  cout << "]" << endl;
}

int main()
{
  cout << "5 => [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]: ";
  test(5);

  cout << "1 => [[1]]: ";
  test(1);

  cout << "9 => [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1],[1,5,10,10,5,1],[1,6,15,20,15,6,1],[1,7,21,35,35,21,7,1],[1,8,28,56,70,56,28,8,1]]: " << endl;
  test(9);

  return 0;
}
