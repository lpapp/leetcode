#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        size_t left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else if (tolower(s[left]) != tolower(s[right])) return false;
            else { ++left; --right; }
        }
        return true;
    }
};

int main()
{
	Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome(" ") << endl;
	return 0;
}
