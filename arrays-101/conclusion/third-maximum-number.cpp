#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
      set<int> maxes;
      for (const int e : nums) {
        maxes.insert(e);
        if (maxes.size() == 4) maxes.erase(maxes.begin());
      };

      return (maxes.size() < 3) ? *maxes.rbegin() : *maxes.begin();
    }
};

int main()
{
  Solution s;

  vector<int> A1{3, 2, 1};
  cout << "[3,2,1] => 1: " << s.thirdMax(A1) << endl;

  vector<int> A2{1, 2};
  cout << "[1,2] => 2: " << s.thirdMax(A2) << endl;

  vector<int> A3{2, 2, 3, 1};
  cout << "[2,2,3,1] => 1: " << s.thirdMax(A3) << endl;

  vector<int> A4{-1};
  cout << "[-1] => -1: " << s.thirdMax(A4) << endl;

  vector<int> A5{-100, 0, -100, -100, 0};
  cout << "[-100, 0, -100, -100, 0] => 0: " << s.thirdMax(A5) << endl;

  vector<int> A6{1, 2, 2, 5, 3, 5};
  cout << "[1,2,2,5,3,5] => 2: " << s.thirdMax(A6) << endl;

  return 0;
}
