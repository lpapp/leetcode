#include <array>
#include <iostream>
#include <string>
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
    vector<int> arr1 = {2, 1};
    cout << s.validMountainArray(arr1) << endl;
    vector<int> arr2 = {3, 5, 5};
    cout << s.validMountainArray(arr2) << endl;
    vector<int> arr3 = {0, 3, 2, 1};
    cout << s.validMountainArray(arr3) << endl;
	return 0;
}
