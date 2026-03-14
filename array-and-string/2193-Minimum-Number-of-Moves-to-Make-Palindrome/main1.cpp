#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        const size_t sLength = s.size();
        int result = 0;
        for (size_t left = 0, right = sLength - 1; left < right; ++left) {
            bool matchFound = false;
            for (size_t searchIdx = right; searchIdx != left; --searchIdx) {
                if (s[left] != s[searchIdx]) continue;
                for (matchFound = true; searchIdx < right; ++searchIdx, ++result) swap(s[searchIdx], s[searchIdx + 1]);
                --right;
                break;
            }
            if (!matchFound) result += sLength / 2 - left;
        }
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.minMovesToMakePalindrome("aabb") << endl;
    cout << s.minMovesToMakePalindrome("letelt") << endl;
	return 0;
}
