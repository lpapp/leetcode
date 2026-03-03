#include <iostream>
#include <string>

using namespace std;

class Solution {
    bool checkPalindromeFormationHelper(const string& prefix, const string& suffix) {
        size_t left = 0, right = suffix.size() - 1;
        while (left < right && prefix[left] == suffix[right]) { ++left; --right; };
        return left >= right || isPalindrome(prefix, left, right) || isPalindrome(suffix, left, right);
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left <= right && s[left] == s[right]) { ++left; --right; }
        return left >= right;
    }

public:
    bool checkPalindromeFormation(string a, string b) {
        return checkPalindromeFormationHelper(a, b) || checkPalindromeFormationHelper(b, a);
    }
};

int main()
{
	Solution s;
    cout << s.checkPalindromeFormation("a", "b") << endl;
    cout << s.checkPalindromeFormation("xbdef", "xecab") << endl;
    cout << s.checkPalindromeFormation("ulacfd", "jizalu") << endl;
	return 0;
}
