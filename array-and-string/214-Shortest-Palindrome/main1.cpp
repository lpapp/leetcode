#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

// original example: aacecaaa
// combined: aacecaaa#aaacecaa
// indices below
// a a c e c a a a # a a  a  c  e  c  a  a
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// longest proper prefix (prefix suffix len) initially
// 0 0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0
// Walkthrough
// i = 1, j = 0 => combined[1] = 'a', combined[0] = 'a' -> match, j = 1, lps[1] = 1
// i=2, j=1 => combined[2]='c', combined[1]='a' -> mismatch, fallback j=prefix_suffix_len[0]=0
//             combined[2]='c', combined[0]='a' -> mismatch, j=0. prefix_suffix_len[2]=0
// i=3, j=0 => combined[3]='e', combined[0]='a' -> mismatch, j=0. prefix_suffix_len[3]=0
// i=4, j=0 => combined[4]='c', combined[0]='a' -> mismatch, j=0. prefix_suffix_len[4]=0
// i=5, j=0 => combined[5]='a', combined[0]='a' -> match, j=1. prefix_suffix_len[5]=1
// i=6, j=1 => combined[6]='a', combined[1]='a' -> match, j=2. prefix_suffix_len[6]=2
// i=7, j=2 => combined[7]='a', combined[2]='c' -> mismatch, fallback j=prefix_suffix_len[1]=1
//             combined[7]='a', combined[1]='a' -> match, j=2. prefix_suffix_len[7]=2
// i=8, j=2 => combined[8]='#', combined[2]='c' -> mismatch, fallback j=prefix_suffix_len[1]=1
//             combined[8]='#', combined[1]='a' -> mismatch, fallback j=prefix_suffix_len[0]=0
//             combined[8]='#', combined[0]='a' -> mismatch, j=0. prefix_suffix_len[8]=0
// i=9,  j=0 => combined[9]='a',  combined[0]='a' -> match, j=1. prefix_suffix_len[9]=1
// i=10, j=1 => combined[10]='a', combined[1]='a' -> match, j=2. prefix_suffix_len[10]=2
// i=11, j=2 => combined[11]='a', combined[2]='c' -> mismatch, fallback j=prefix_suffix_len[1]=1
//              combined[11]='a', combined[1]='a' -> match, j=2. prefix_suffix_len[11]=2
// i=12, j=2 => combined[12]='c', combined[2]='c' -> match, j=3. prefix_suffix_len[12]=3
// i=13, j=3 => combined[13]='e', combined[3]='e' -> match, j=4. prefix_suffix_len[13]=4
// i=14, j=4 => combined[14]='c', combined[4]='c' -> match, j=5. prefix_suffix_len[14]=5
// i=15, j=5 => combined[15]='a', combined[5]='a' -> match, j=6. prefix_suffix_len[15]=6
// i=16, j=6 => combined[16]='a', combined[6]='a' -> match, j=7. prefix_suffix_len[16]=7

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s.rbegin(), s.rend());
        string combined = s + "#" + rev;
        const int n = combined.size();
        vector<int> prefix_suffix_len(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = prefix_suffix_len[i - 1];
            while (j > 0 && combined[i] != combined[j]) j = prefix_suffix_len[j - 1];
            if (combined[i] == combined[j]) ++j;
            prefix_suffix_len[i] = j;
        }
        return rev.substr(0, s.size() - prefix_suffix_len.back()) + s;
    }
};

int main()
{
	Solution s;
    assert(s.shortestPalindrome("aacecaaa") == "aaacecaaa");
    assert(s.shortestPalindrome("abcd") == "dcbabcd");
	return 0;
}
