#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        array<int, 26> charFrequency = {0};
        for (const char ch : s) ++charFrequency[ch - 'a'];
        int oddFrequencyCount = 0;
        for (const int frequency : charFrequency) {
            if (frequency & 1) oddFrequencyCount++;
        }
        return oddFrequencyCount <= k;
    }
};

int main()
{
	Solution s;
    cout << s.canConstruct("annabelle", 2) << endl;
    cout << s.canConstruct("leetcode", 3) << endl;
    cout << s.canConstruct("true", 4) << endl;
	return 0;
}
