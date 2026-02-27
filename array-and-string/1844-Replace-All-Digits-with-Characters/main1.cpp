#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        const size_t stringLength = s.size();
        for (size_t i = 1; i < stringLength; i += 2) {
            char previousChar = s[i - 1];
            int shiftAmount = s[i] - '0';
            s[i] = previousChar + shiftAmount;
        }
        return s;
    }
};

int main()
{
	Solution s;
    cout << s.replaceDigits("a1c1e1") << endl;
    cout << s.replaceDigits("a1b2c3d4e") << endl;
	return 0;
}
