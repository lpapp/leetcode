#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        const size_t stringLength = s.size();
        for (size_t i = 0; i < stringLength; ++i) {
            if (s[i] != '?') continue;
            for (const char candidateChar : "abc") {
                const bool hasLeftConflict = (i > 0 && s[i - 1] == candidateChar);
                if (hasLeftConflict) continue;
                const bool hasRightConflict = (i + 1 < stringLength && s[i + 1] == candidateChar);
                if (hasRightConflict) continue;
                s[i] = candidateChar;
                break;
            }
        }
      
        return s;
    }
};

int main()
{
	Solution s;
    cout << s.modifyString("?zs") << endl;
    cout << s.modifyString("ubv?w") << endl;
	return 0;
}
