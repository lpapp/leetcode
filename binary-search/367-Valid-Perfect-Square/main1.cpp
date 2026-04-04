#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int result = -1;
		for (int left = 1, right = num; left <= right;) {
            const int mid = left + ((right - left) >> 1);
            if (static_cast<int64_t>(mid) * mid >= num) { result = mid; right = mid - 1; }
			else left = mid + 1;
        }
        return result != -1 && static_cast<int64_t>(result) * result == num;
    }
};

int main()
{
	Solution s;
    cout << s.isPerfectSquare(16) << endl;
    cout << s.isPerfectSquare(14) << endl;
	return 0;
}
