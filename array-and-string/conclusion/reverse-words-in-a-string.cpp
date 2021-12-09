#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      string reversed;
      int N = s.size(), word_end = N - 1;
      for (int i = N - 1; i >= 0;) {
        if (s[i] == ' ') {
          int ti = i;
          while (i >= 0 and s[i] == ' ') --i;
          if (i < 0) break;
          if (ti != N - 1) reversed.push_back(' ');
        }

        word_end = i;
        while (i >= 0 and s[i] != ' ') --i;
        for (int k = i + 1; k <= word_end; ++k) reversed.push_back(s[k]);
        if (i < 0) break;
      }
      return reversed;
    }
};

int main()
{
  Solution s;

  string S1 = "the sky is blue";
  cout << "'the sky is blue' => 'blue is sky the': '" << s.reverseWords(S1) << "'" << endl;

  string S2 = "  hello world  ";
  cout << "'  hello world  ' => 'world hello': '" << s.reverseWords(S2) << "'" << endl;

  string S3 = "a good   example";
  cout << "'a good   example' => 'example good a': '" << s.reverseWords(S3) << "'" << endl;

  string S4 = "  Bob    Loves  Alice   ";
  cout << "'  Bob    Loves  Alice   ' => 'Alice Loves Bob': '" << s.reverseWords(S4) << "'" << endl;

  string S5 = "Alice does not even like bob";
  cout << "'Alice does not even like bob' => 'bob like even not does Alice': '" << s.reverseWords(S5) << "'" << endl;

  return 0;
}
