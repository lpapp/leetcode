#include <iostream>

using namespace std;

int guess(int num) { return 0; }

class Solution {
public:
    int guessNumber(int n) {
        int result = -1;
        for (int left = 1, right = n; left <= right;) {
            int mid = left + ((right - left) >> 1);
            if (guess(mid) <= 0) { result = mid; right = mid - 1; }
			else left = mid + 1;
        }
        return result;      
    }
};

int main()
{
	Solution s;
    cout << s.guessNumber(10) << endl;
    cout << s.guessNumber(1) << endl;
    cout << s.guessNumber(2) << endl;
	return 0;
}
