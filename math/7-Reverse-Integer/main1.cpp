#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        for (; x; result = result * 10 + x % 10, x /= 10) if (result > numeric_limits<int>::max() / 10 || result < numeric_limits<int>::min() / 10) return 0;
        return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.reverse(123) << endl;
	cout << solution.reverse(-123) << endl;
	cout << solution.reverse(120) << endl;
	return 0;
}
