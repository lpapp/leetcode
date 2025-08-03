#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Runtime Complexity: O(n)
//
// Space complexity:   O(1)
//
// n: length of the string

class Solution {
    static bool isPalindrome(const std::string& s, std::size_t left, std::size_t right) {
        for (; left < right; ++left, --right) {
            if (s[left] != s[right]) return false;
        }
        
        return true;
    }

public:
    bool validPalindrome(string s) {
        for (std::size_t left = 0, right = s.size() - 1; left < right; ++left, --right) {
            if (s[left] != s[right]) return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }

        return true;
    }
};


int main()
{
  Solution solution;
  std::cout << solution.validPalindrome("aba") << std::endl;
  std::cout << solution.validPalindrome("abca") << std::endl;
  std::cout << solution.validPalindrome("abc") << std::endl;

  return 0;
}
