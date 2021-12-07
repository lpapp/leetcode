#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr_bruteforce(string haystack, string needle) {
      for (int i = 0, j = 0, H = haystack.size(), N = needle.size(); i < H - N + 1; ++i) {
        for (j = 0; j < N and needle[j] == haystack[i + j]; ++j);
        if (j == N) return i;
      }
      return -1;
    }

    // KMP string matching, CLRS Chapter 32.4
    vector<int> kmp_precompute_prefix(string needle)
    {
      const size_t M = needle.size();
      vector<int> kmp_precompute(1, 0);
      kmp_precompute.reserve(M);
      for (size_t k = 0, q = 1; q < M; ++q) {
        while (k and needle[k + 1] != needle[q]) k = kmp_precompute[k - 1];
        if (needle[k] == needle[q]) ++k;
        kmp_precompute.push_back(k);
      }
      return kmp_precompute;
    }

    int strStr(string haystack, string needle) {
      if (needle.empty()) return 0;
      const size_t N = haystack.size(), M = needle.size();
      if (M > N) return -1;
      vector<int> kmp_precompute = kmp_precompute_prefix(needle);
      for (size_t i = 0, q = 0; i < N; ++i) {
        while (q and needle[q] != haystack[i]) q = kmp_precompute[q - 1];
        if (needle[q] == haystack[i]) ++q;
        if (q == M) return i + 1 - M;
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

  string H6 = "hello world", N6 = "hello";
  cout << "hello world | hello => 0: " << s.strStr(H6, N6) << endl;

  string H7 = "hello world", N7 = "world";
  cout << "hello world | world => 6: " << s.strStr(H7, N7) << endl;

  string H8 = "a", N8 = "";
  cout << "a | '' => 0: " << s.strStr(H8, N8) << endl;

  string H9 = "mississippi", N9 = "issip";
  cout << "mississippi | issip => 4: " << s.strStr(H9, N9) << endl;

  string H10 = "aaa", N10 = "aabab";
  cout << "aaa | aabab => -1: " << s.strStr(H10, N10) << endl;

  string H11 = "aabaaabaaac", N11 = "aabaaac";
  cout << "aabaaabaaac | aabaaac => 4: " << s.strStr(H11, N11) << endl;

  return 0;
}
