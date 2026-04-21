#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
      vector<int> expected = heights; sort(expected.begin(), expected.end());
      int result = 0;
      for (size_t i = 0; i < heights.size(); ++i) if (heights[i] != expected[i]) ++result;
      return result;
    }
};

int main()
{
	Solution s;
    vector<int> heights1 = {1, 1, 4, 2, 1, 3};
    cout << s.heightChecker(heights1) << endl;
    vector<int> heights2 = {5, 1, 2, 3, 4};
    cout << s.heightChecker(heights2) << endl;
    vector<int> heights3 = {1, 2, 3, 4, 5};
    cout << s.heightChecker(heights3) << endl;
	return 0;
}
