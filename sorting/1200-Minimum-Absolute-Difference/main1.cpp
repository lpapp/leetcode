#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = 1 << 30, arrLength = arr.size();
        for (int i = 0; i < arrLength - 1; ++i) minDiff = min(minDiff, arr[i + 1] - arr[i]);
        vector<vector<int>> result;
        for (int i = 0; i < arrLength - 1; ++i) if (arr[i + 1] - arr[i] == minDiff) result.push_back({arr[i], arr[i + 1]});
        return result;       
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int& i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<int> arr1 = {4, 2, 1, 3};
    printVectorVector(s.minimumAbsDifference(arr1));
    vector<int> arr2 = {1, 3, 6, 10, 15};
    printVectorVector(s.minimumAbsDifference(arr2));
    vector<int> arr3 = {3, 8, -10, 23, 19, -4, -14, 27};
    printVectorVector(s.minimumAbsDifference(arr3));
	return 0;
}
