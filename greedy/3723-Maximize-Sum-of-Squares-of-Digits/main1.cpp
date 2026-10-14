#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";
        const int nineCount = sum / 9, remainder = sum % 9;
        string res(num, '0');
        for (int i = 0; i < nineCount; ++i) res[i] = '9';
        if (remainder) res[nineCount] = '0' + remainder;
        return res;   
    }
};

int main()
{
    Solution s;
    assert(s.maxSumOfSquares(2, 3) == "30");
    assert(s.maxSumOfSquares(2, 17) == "98");
    assert(s.maxSumOfSquares(1, 10) == "");
    return 0;
}
