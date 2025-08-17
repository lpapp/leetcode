#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(logn)
// Space complexity: O(1)

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= mid) right = mid;
            else left = mid + 1;
        }

        return arr[left] == left ? left : -1;
    }
};

int main()
{
	Solution solution;
	vector<int> input1 = {-10, -5, 0, 3, 7};
	cout << solution.fixedPoint(input1) << endl;
	return 0;
}
