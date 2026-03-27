#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        for (unsigned int carry; b; a = a ^ b, b = carry) carry = (static_cast<unsigned int>(a & b)) << 1;
        return a;
    }
};

int main()
{
	Solution solution;
	cout << solution.getSum(1, 2) << endl;
	cout << solution.getSum(2, 3) << endl;
	return 0;
}
