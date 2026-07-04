#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        if (k-- > 3 * (1 << (n - 1))) return "";
        string res; res.reserve(n);
        int groupSize = 1 << (n - 1);
        res.push_back('a' + k / groupSize);
        k %= groupSize;
        for (int i = 1; i < n; ++i) {
            groupSize >>= 1;
            const int choice = k / groupSize;
            k %= groupSize;
            const char prev = res[i - 1];
            int idx = 0;
            for (char c = 'a'; c <= 'c'; ++c) {
                if (c != prev) {
                    if (idx == choice) { res.push_back(c); break; }
                    ++idx;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.getHappyString(1, 3) == "c");
    assert(s.getHappyString(1, 4) == "");
    assert(s.getHappyString(3, 9) == "cab");
    return 0;
}
