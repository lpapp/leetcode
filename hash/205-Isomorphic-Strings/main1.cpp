#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array<int, 256> sHash = {0}, tHash = {0};
      	const size_t sLength = s.size();
        for (size_t i = 0; i < sLength; ++i) {
            const char sc = s[i], tc = t[i];
            if (sHash[sc] != tHash[tc]) return false;
            sHash[sc] = i + 1, tHash[tc] = i + 1;
        }
        return true;
    }
};

int main()
{
	Solution s;
    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("f11", "b23") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
	return 0;
}
