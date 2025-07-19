#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check that s and goal are equal length and not empty
        if (const size_t sSize = s.size(); sSize == goal.size() && sSize > 0) {
            // Concatenate s and goal within a new string
            const string concatenatedString = s + s;
            return concatenatedString.contains(goal);
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.rotateString("abcde", "cdeab") << true << endl;
    cout << s.rotateString("abcde", "abced") << false << endl;
    cout << s.rotateString("waterbottle", "erbottlewat") << true << endl;
    return 0;
}
