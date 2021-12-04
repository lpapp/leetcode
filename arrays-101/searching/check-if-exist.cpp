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



    bool checkIfExist(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      const int N = arr.size();
      for (int i = 0; i < N; ++i) {
        for (int left = 0, right = N - 1, mid = (left + right) / 2; left <= right; mid = (left + right) / 2) {
          if (arr[i] * 2 == arr[mid] and mid != i) return true;
          else if (arr[i] * 2 < arr[mid]) right = mid - 1;
          else left = mid + 1;
        }
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

  vector<int> A4{-20, 8, -6, -14, 0, -19, 14, 4};
  cout << "[-20,8,-6,-14,0,-19,14,4] => true: " << s.checkIfExist(A4) << endl;

  vector<int> A5{-2, 0, 10, -19, 4, 6, -8};
  cout << "[-2,0,10,-19,4,6,-8] => false: " << s.checkIfExist(A5) << endl;

  vector<int> A6{-19, -8, -2, 0, 0, 6, 10};
  cout << "[-19, -8, -2, 0, 0, 6, 10] => true: " << s.checkIfExist(A6) << endl;

  vector<int> A7{-19, -8, 0, 0, 4, 6, 10};
  cout << "[-19, -8, 0, 0, 4, 6, 10] => true: " << s.checkIfExist(A7) << endl;

  return 0;
}
