#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n-1));
    }
};

int main()
{
    Solution solution;
    cout << solution.isPowerOfTwo(1) << endl;
    cout << solution.isPowerOfTwo(16) << endl;
    cout << solution.isPowerOfTwo(3) << endl;
    cout << solution.isPowerOfTwo(0) << endl;
    cout << solution.isPowerOfTwo(-2147483648) << endl;
    return 0;
}
