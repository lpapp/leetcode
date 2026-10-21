#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        const int n = s.size();
        char lo = s[0], hi = s[0];
        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] < s[i - 1]) sorted = false;
            lo = min(lo, s[i]);
            hi = max(hi, s[i]);
        }
        if (sorted) return 0;
        if (n == 2) return -1;
        if (s[0] == lo || s[n - 1] == hi) return 1;
        for (int i = 1; i < n - 1; ++i) if (s[i] == lo || s[i] == hi) return 2;
        return 3;    
    }
};

int main()
{
    Solution s;
    assert(s.minOperations("dog") == 1);
    assert(s.minOperations("card") == 2);
    assert(s.minOperations("gf") == -1);
    return 0;
}
