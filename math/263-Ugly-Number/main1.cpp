#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (const int p : {2, 3, 5}) while (n % p == 0) n /= p;
        return n == 1;
    }
};

int main()
{
    Solution solution;
    assert(solution.isUgly(6));
    assert(solution.isUgly(1));
    assert(!solution.isUgly(14));
    return 0;
}
