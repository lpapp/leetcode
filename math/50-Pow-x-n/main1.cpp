#include <cmath>
#include <iostream>

using namespace std;

class Solution {
    double myPowHelper(double base, long long exponent) {
        double result = 1.0;
        for (; exponent > 0; base *= base, exponent >>= 1) if (exponent & 1) result *= base;
        return result;
    }
public:
    double myPow(double x, int n) {
        return n >= 0 ? myPowHelper(x, n) : 1.0 / myPowHelper(x, -(uint64_t)n);
    }
};

int main()
{
	Solution solution;
	cout << solution.myPow(2.00000, 10) << endl;
	cout << solution.myPow(2.10000, 3) << endl;
	cout << solution.myPow(2.00000, -2) << endl;
	return 0;
}
