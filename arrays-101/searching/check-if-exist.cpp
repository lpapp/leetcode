#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIfExist_slow(vector<int>& arr) {
      for (const int e : arr) {
        for (const int f : arr) {
          if (e == 2 * f) return true;
        } 
      }
      return false;
    }

    bool checkIfExist_hash(vector<int>& arr) {
      unordered_set<int> arr_hash;
      for (const int e : arr) {
        if (arr_hash.count(2 * e) or (!(e & 1) and arr_hash.count(e/2))) return true;
        arr_hash.insert(e);
      }
      return false;
    }
};

int main()
{
  Solution s;

  vector<int> A1{10, 2, 5, 3};
  cout << "[10,2,5,3] => true: " << s.checkIfExist(A1) << endl;

  vector<int> A2{7, 1, 14, 11};
  cout << "[7,1,14,11] => true: " << s.checkIfExist(A2) << endl;

  vector<int> A3{3, 1, 7, 11};
  cout << "[3,1,7,11] => false: " << s.checkIfExist(A3) << endl;

  return 0;
}
