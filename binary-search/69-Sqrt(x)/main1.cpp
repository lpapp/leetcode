#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        int result = -1;
        for (int left = 1, right = x; left <= right; ) {
            int mid = left + ((right - left) >> 1);
            if (mid > (x / mid)) { result = mid; right = mid - 1; }
            else left = mid + 1;
        }
        if (result == -1) return x;
        return result - 1;       
    }
};

int main()
{
	Solution s;
    cout << s.mySqrt(4) << endl;
    cout << s.mySqrt(8) << endl;
	return 0;
}
