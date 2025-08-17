#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int magicFast(vector<int>& arr, int start, int end) {
        if (end < start) return -1;

        int mid = (start + end) / 2;
        if (arr[mid] == mid) return mid;
        else if (arr[mid] > mid) return magicFast(arr, start, mid - 1);

        return magicFast(arr, mid + 1, end);
    }
public:
    int fixedPoint(vector<int>& arr) {
        return magicFast(arr, 0, arr.size());
    }
};

int main()
{
	Solution solution;
	vector<int> input1 = {-10, -5, 0, 3, 7};
	cout << solution.fixedPoint(input1) << endl;
	return 0;
}
