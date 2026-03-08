#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        const size_t sLength = s.size();
        const int numberOfAllSubsequences = 1 << sLength;
        vector<bool> isPalindrome(numberOfAllSubsequences, true);
        for (int mask = 1; mask < numberOfAllSubsequences; ++mask) {
            for (int left = 0, right = sLength - 1; left < right; ++left, --right) {
                while (left < right && !(mask >> left & 1)) ++left;
                while (left < right && !(mask >> right & 1)) --right;
                if (left < right && s[left] != s[right]) { isPalindrome[mask] = false; break; }
            }
        }
      
        int maxProductValue = 0;
        for (int firstMask = 1; firstMask < numberOfAllSubsequences; ++firstMask) {
            if (!isPalindrome[firstMask]) continue;
            const int firstLength = __builtin_popcount(firstMask);
            const int complementMask = (numberOfAllSubsequences - 1) ^ firstMask;
            for (int secondMask = complementMask; secondMask > 0; secondMask = (secondMask - 1) & complementMask) {
                if (isPalindrome[secondMask]) {
                    const int secondLength = __builtin_popcount(secondMask);
                    maxProductValue = max(maxProductValue, firstLength * secondLength);
                }
            }
        }
      
        return maxProductValue;       
    }
};

int main()
{
	Solution s;
    cout << s.maxProduct("leetcodecom") << endl;
    cout << s.maxProduct("bb") << endl;
    cout << s.maxProduct("accbcaxxcxx") << endl;
	return 0;
}
