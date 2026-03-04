#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int centerIndex = 0, sLength = s.size(), numberOfCenters = sLength * 2 - 1; centerIndex < numberOfCenters; ++centerIndex) {
            for (int left = centerIndex / 2, right = (centerIndex + 1) / 2;left >= 0 && right < sLength && s[left] == s[right]; ++result, --left, ++right);
        }
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.countSubstrings("abc") << endl;
    cout << s.countSubstrings("aaa") << endl;
	return 0;
}
