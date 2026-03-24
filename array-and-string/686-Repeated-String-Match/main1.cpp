#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        const size_t aLength = a.size(), bLength = b.size();
        int result = (bLength + aLength - 1) / aLength;
        string aRepeated = "";
        for (int i = 0; i < result; ++i) aRepeated += a;
        for (int i = 0; i < 3; ++i, ++result, aRepeated += a) if (aRepeated.contains(b)) return result;
        return -1;
    }
};

int main()
{
	Solution s;
    cout << s.repeatedStringMatch("abcd", "cdabcdab") << endl;
    cout << s.repeatedStringMatch("a", "aa") << endl;
	return 0;
}
