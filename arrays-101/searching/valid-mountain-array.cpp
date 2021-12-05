#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
      if (arr.size() < 3 or arr[1] <= arr[0]) return false;
      bool increasing = true;
      for (size_t i = 2; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) return false;
        else if (increasing and arr[i] < arr[i - 1]) increasing = 0;
        else if (!increasing and arr[i] > arr[i - 1]) return false;
      }
      return !increasing; 
    }
};

int main()
{
  Solution s;

  vector<int> A1{2, 1};
  cout << "[2,1] => false: " << s.validMountainArray(A1) << endl;

  vector<int> A2{3, 5, 5};
  cout << "[3, 5, 5] => false: " << s.validMountainArray(A2) << endl;

  vector<int> A3{0, 3, 2, 1};
  cout << "[0, 3, 2, 1] => true: " << s.validMountainArray(A3) << endl;

  vector<int> A4{1, 2, 3, 4, 5};
  cout << "[1, 2, 3, 4, 5] => false: " << s.validMountainArray(A4) << endl;

  vector<int> A5{4, 4, 3, 2, 1};
  cout << "[4,4,3,2,1] => false: " << s.validMountainArray(A5) << endl;

  return 0;
}
