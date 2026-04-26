#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        size_t arrLength = arr.size(), left = 0, right = arrLength - 1;
        if (arrLength < 3) return false;
        while (left + 1 < arrLength - 1 && arr[left] < arr[left + 1]) ++left;
        while (right - 1 > 0 && arr[right - 1] > arr[right]) --right;
        return left == right;
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
