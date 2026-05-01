#include <algorithm>
#include <array>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 'z' - 'a' + 1> letters = {};
        for (size_t i = 0; i < s.size(); ++i) { ++letters[s[i] - 'a']; --letters[t[i] - 'a']; }
        return all_of(letters.cbegin(), letters.cend(), [](int count) { return count == 0; });
    }
};

int main()
{
    Solution solution;
    assert(solution.isAnagram("anagram", "nagaram"));
    assert(!solution.isAnagram("rat", "car"));
    return 0;
}
