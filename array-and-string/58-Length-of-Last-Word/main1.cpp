#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1;
        while (right >= 0 && s[right] == ' ') --right;
        int left = right;
        while (left >= 0 && s[left] != ' ') --left;
        return right - left;      
    }
};

int main()
{
	Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cout << s.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << s.lengthOfLastWord("luffy is still joyboy") << endl;
	return 0;
}
