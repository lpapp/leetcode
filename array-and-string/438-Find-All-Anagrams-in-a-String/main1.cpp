#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const size_t sLength = s.size(), pLength = p.size();
		if (sLength < pLength) return {};
		vector<int> result;

		array<int, 26> patternCount = {0};
		for (const char ch: p) ++patternCount[ch - 'a'];

		array<int, 26> windowCount = {0};
		for (size_t i = 0; i < pLength - 1; ++i) ++windowCount[s[i] - 'a'];
		for (size_t i = pLength - 1; i < sLength; i++) {
			++windowCount[s[i] - 'a'];
			if (windowCount == patternCount) result.push_back(i - pLength + 1);
			--windowCount[s[i - pLength + 1] - 'a'];
		}

		return result;
    }
};

void printSolution(vector<int> input)
{
    for (const int& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
    printSolution(s.findAnagrams("cbaebabacd", "abc"));
    printSolution(s.findAnagrams("abab", "ab"));
	return 0;
}
