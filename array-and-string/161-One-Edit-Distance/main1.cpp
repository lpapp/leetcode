#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        const size_t sLength = s.size(), tLength = t.size();
        if (sLength < tLength) return isOneEditDistance(t, s);
        if (sLength - tLength > 1) return false;
        for (size_t i = 0; i < tLength; ++i) {
            if (s[i] != t[i]) {
                if (sLength == tLength) return s.substr(i + 1) == t.substr(i + 1);
                return s.substr(i + 1) == t.substr(i);
            }
        }
        return sLength == tLength + 1;
    }
};

int main()
{
	Solution s;
    cout << s.isOneEditDistance("cab", "ab") << endl;
    cout << s.isOneEditDistance("abc", "adc") << endl;
	return 0;
}
