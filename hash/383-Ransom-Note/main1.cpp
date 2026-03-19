#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> hash = {};
        for (const char c : magazine) ++hash[c - 'a'];
        for (const char c : ransomNote) if (--hash[c - 'a'] < 0) return false;
      
        return true;
    }
};

int main()
{
	Solution s;
    cout << s.canConstruct("a", "b") << endl;
    cout << s.canConstruct("aa", "ab") << endl;
    cout << s.canConstruct("aa", "aab") << endl;
	return 0;
}
