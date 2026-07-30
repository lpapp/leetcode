#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        const int n = word.size();
        return n <= 8 ? n : n <= 16 ? 8 + (n - 8) * 2 : n <= 24 ? 24 + (n - 16) * 3 : 48 + (n - 24) * 4;
    }
};

int main()
{
    Solution s;
    assert(s.minimumPushes("abcde") == 5);
    assert(s.minimumPushes("xycdefghij") == 12);
    return 0;
}
