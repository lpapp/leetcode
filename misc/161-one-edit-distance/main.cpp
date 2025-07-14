#include <array>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        const int sSize = s.size();
        const int tSize = t.size();
        if (std::abs(sSize - tSize) > 1) return false;

        string shortString = sSize < tSize ? s : t;
        string longString = sSize < tSize ? t : s;

        bool foundDifference = false;
        const int shortStringSize = shortString.size();
        const int longStringSize = longString.size();
        for (int shortIndex = 0, longIndex = 0; longIndex < longStringSize && shortIndex < shortStringSize; ++longIndex) {
            if (shortString[shortIndex] != longString[longIndex]) {
                /* Ensure that this is the first difference found. */
                if (foundDifference) return false;
                foundDifference = true;
                // On replace, move the shorter pointer
                if (shortStringSize == longStringSize) ++shortIndex;
            } else {
                ++shortIndex; // If matching, move the shorter pointer
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.isOneEditDistance("pale", "ple") << endl;
    cout << solution.isOneEditDistance("pales", "pale") << endl;;
    cout << solution.isOneEditDistance("pale", "bale") << endl;;
    cout << solution.isOneEditDistance("pale", "bae") << endl;;
    return 0;
}
