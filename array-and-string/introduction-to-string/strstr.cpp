#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
      for (int i = 0, j = 0, H = haystack.size(), N = needle.size(); i < H - N + 1; ++i) {
        for (j = 0; j < N and needle[j] == haystack[i + j]; ++j);
        if (j == N) return i;
      }
      return -1;
    }
};

int main()
{
  Solution s;

  string H1 = "hello", N1 = "ll";
  cout << "hello | ll => 2: " << s.strStr(H1, N1) << endl;

  string H2 = "aaaaa", N2 = "bba";
  cout << "aaaaa | bba => -1: " << s.strStr(H2, N2) << endl;

  string H3 = "", N3 = "";
  cout << "'' | '' => 0: " << s.strStr(H3, N3) << endl;

  string H4 = "", N4 = "a";
  cout << "'' | a => -1: " << s.strStr(H4, N4) << endl;

  string H5 = "a", N5 = "a";
  cout << "a | a => 0: " << s.strStr(H5, N5) << endl;

  return 0;
}
