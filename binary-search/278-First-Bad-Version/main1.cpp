#include <iostream>

using namespace std;

bool isBadVersion(int version) { return version; }

class Solution {
public:
    int firstBadVersion(int n) {
        int result = -1;
        for (int left = 1, right = n; left <= right;) {
            int mid = left + ((right - left) >> 1);
            if (isBadVersion(mid)) { result = mid; right = mid - 1; }
			else left = mid + 1;
        }
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.firstBadVersion(5) << endl;
    cout << s.firstBadVersion(1) << endl;
	return 0;
}
