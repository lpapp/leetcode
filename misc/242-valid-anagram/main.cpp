#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        array<int, 'z'-'a'+1> letters;
        for (const char c : s) ++letters[c];

        for (const char c : t) {
            if (--letters[c] < 0) return false;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.isAnagram("anagram", "nagaram") << endl;
    cout << solution.isAnagram("rat", "car") << endl;;
    return 0;
}
