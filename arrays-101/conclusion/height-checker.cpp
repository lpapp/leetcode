#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
      int diff = 0;
      vector<int> sorted_heights = heights;
      sort(sorted_heights.begin(), sorted_heights.end());
      for (size_t i = 0; i < heights.size(); ++i) if (heights[i] != sorted_heights[i]) ++diff;
      return diff;       
    }
};

int main()
{
  Solution s;

  vector<int> A1{1, 1, 4, 2, 1, 3};
  cout << "[1,1,4,2,1,3] | [1,1,1,2,3,4] => 3: " << s.heightChecker(A1) << endl;

  vector<int> A2{5, 1, 2, 3, 4};
  cout << "[5,1,2,3,4] | [1,2,3,4,5] => 5: " << s.heightChecker(A2) << endl;

  vector<int> A3{1, 2, 3, 4, 5};
  cout << "[1,2,3,4,5] | [1,2,3,4,5] => 0: " << s.heightChecker(A3) << endl;

  vector<int> A4{1};
  cout << "[1] | [1] => 0: " << s.heightChecker(A4) << endl;

  return 0;
}
