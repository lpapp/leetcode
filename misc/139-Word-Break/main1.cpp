#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Recursive
// Time complexity: O(2 ^ N).
// Space complexity: O(N ^ 2)
// N: string length

bool wordBreak(const string& s, vector<string>& wordDict)
{
    // Base case of the recursion
    if (s.empty())
        return true;

    const std::size_t slen = s.length();

    // One prefix may not work, so have to try all prefixes
    for (std::size_t i = 1; i <= slen; ++i) {
        const string prefix = s.substr(0, i);
	// If the current prefix is in the dictionary and remaining part can
	// also be broken into dictionary words, then the string input can be
        // segmented.
        if (find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end()
            && wordBreak(s.substr(i), wordDict)) {
            return true;
        }
    }

    // Cannot be segmented if none of the prefixes can be segmented.
    return false;
}


int main()
{
    vector<string> d = { "mobile", "samsung",  "sam",  "sung", "man",
                         "mango",  "icecream", "and",  "go",   "i",
                         "like",   "ice",      "cream" };
    
    cout << (wordBreak("ilikesamsung", d) ? "Yes\n" : "No\n");
    cout << (wordBreak("iiiiiiii", d) ? "Yes\n" : "No\n");
    cout << (wordBreak("", d) ? "Yes\n" : "No\n");
    cout << (wordBreak("ilikelikeimangoiii", d) ? "Yes\n" : "No\n");
    cout << (wordBreak("samsungandmango", d) ? "Yes\n" : "No\n");
    cout << (wordBreak("samsungandmangok", d) ? "Yes\n" : "No\n");

    return 0;
}
