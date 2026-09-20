#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x && !(x % 10))) return false;
        int rev = 0;
        for (; rev < x; x /= 10) rev = rev * 10 + x % 10;
        return x == rev || x == rev / 10;
    }
};

int main()
{
    Solution s;
    assert(s.isPalindrome(121));
    assert(!s.isPalindrome(-121));
    assert(!s.isPalindrome(10));
    return 0;
}
