#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        int result = 0;
        for (int next = 1, tmp; n--; result = next, next = tmp) tmp = result + next;
        return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.fib(2) << endl;
	cout << solution.fib(3) << endl;
	cout << solution.fib(4) << endl;
	return 0;
}
