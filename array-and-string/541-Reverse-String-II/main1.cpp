#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        const size_t sLength = s.size();
        for (size_t start = 0; start < sLength; start += 2 * k) {
            const size_t end = min(start + k, sLength);
            reverse(s.begin() + start, s.begin() + end);
        }
        return s;
    }
};

int main()
{
	Solution s;
    cout << s.reverseStr("abcdefg", 2) << endl;
    cout << s.reverseStr("abcd", 2) << endl;
	return 0;
}
