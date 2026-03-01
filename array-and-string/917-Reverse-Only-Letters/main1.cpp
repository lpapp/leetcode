#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        size_t left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalpha(s[left])) ++left;
            while (left < right && !isalpha(s[right])) --right;
            if (left < right) swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main()
{
	Solution s;
    cout << s.reverseOnlyLetters("ab-cd") << endl;
    cout << s.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
    cout << s.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;
	return 0;
}
