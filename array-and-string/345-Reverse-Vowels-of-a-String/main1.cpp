#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        array<bool, 128> isVowel = {};
        for (const char c : "aeiouAEIOU") isVowel[c] = true;
        size_t left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isVowel[s[left]]) ++left;
            while (left < right && !isVowel[s[right]]) --right;
            if (left < right) swap(s[left++], s[right--]);
        }
      
        return s;   
    }
};

int main()
{
	Solution s;
    cout << s.reverseVowels("IceCreAm") << endl;
    cout << s.reverseVowels("leetcode") << endl;
	return 0;
}
