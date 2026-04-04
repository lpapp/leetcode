#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        for (int right = arr.size() - k; left < right;) {
            const int mid = (left + right) >> 1;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.cbegin() + left, arr.cbegin() + left + k);
    }
};

void printVector(vector<int> input)
{
    for (const int item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
	vector<int> arr1 = {1, 2, 3, 4, 5};
    printVector(s.findClosestElements(arr1, 4, 3));
	vector<int> arr2 = {1, 1, 2, 3, 4, 5};
    printVector(s.findClosestElements(arr2, 4, -1));
	vector<int> arr3 = {1};
    printVector(s.findClosestElements(arr3, 1, 1));
	return 0;
}
