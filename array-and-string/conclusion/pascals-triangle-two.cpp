#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow_inefficient(int rowIndex) {
      const int numRows = 34;
      vector<vector<int>> pascals_triangle(numRows, vector<int>{1});
      for (int row = 1; row < numRows; ++row) pascals_triangle[row].reserve(row + 1);
      for (int row = 1; row < numRows; pascals_triangle[row].push_back(1), ++row) {

        for (int column = 1; column < row; ++column) {
          pascals_triangle[row].push_back(pascals_triangle[row - 1][column - 1] + pascals_triangle[row - 1][column]);
        }
      };
      return pascals_triangle[rowIndex];
    }

    vector<int> getRow(int rowIndex) {
      vector<int> prev_row{1}; prev_row.reserve(rowIndex);
      vector<int> curr_row{1}; curr_row.reserve(rowIndex + 1);
      for (int row = 1; row < rowIndex + 1; curr_row.push_back(1), prev_row = curr_row, ++row) {
        for (int column = 1; column < row; ++column) curr_row[column] = prev_row[column - 1] + prev_row[column];
      };
      return curr_row;
    }
};

void test(int rowIndex)
{
  Solution s;

  cout << "[";
  for (const int e : s.getRow(rowIndex)) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  cout << "3 => [1,3,3,1]: ";
  test(3);

  cout << "0 => [1]: ";
  test(0);

  cout << "1 => [1,1]: ";
  test(1);

  cout << "4 => [1,4,6,4,1]: ";
  test(4);

  return 0;
}
