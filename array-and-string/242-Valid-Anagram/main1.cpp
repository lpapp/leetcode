#include <array>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 'z' - 'a' + 1> letters = {};
        for (const char c : s) ++letters[c - 'a'];
        for (const char c : t) if (--letters[c - 'a'] < 0) return false;
        return true;
    }
};

int main()
{
    Solution solution;
    assert(solution.isAnagram("anagram", "nagaram"));
    assert(!solution.isAnagram("rat", "car"));
    return 0;
}
