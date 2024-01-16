#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords_inefficient(string s) {
      string reversed;
      const int N = s.size();
      for (int i = N - 1, word_end = i, space_start; i >= 0;) {
        if (s[i] == ' ') {
          for (space_start = i; i < N and s[i] == ' '; --i);
          if (i < 0) break;
          if (space_start) reversed.push_back(' ');
        }

        for (word_end = i; i >= 0 and s[i] != ' '; --i);
        for (int k = i + 1; k <= word_end; ++k) reversed.push_back(s[k]);
      }
      return reversed;
    }

   /* string reverseWords(string s) {
     cout << endl;
     reverse(s.begin(), s.end());
     // cout << "REVERSED ORIGINAL STRING: " << s << endl;
     int write = 0;
     for (size_t N = s.size(), i = 0, word_start = 0, space_start; i < N; ++i) {
       if (s[i] == ' ') {
         for (space_start = i; i < N and s[i] == ' '; ++i);
         if (i == N) break;
         if (space_start) s[write++] = ' ';
       }

       for (word_start = i; i < N and s[i] != ' '; ++i);
       // cout << "WORD: " << s.substr(word_start, i - 1);
       // cout << "WORD START: " << word_start << endl;
       // cout << "WORD END: " << i - 1 << endl;
       // cout << "WRITE: " << write << endl;
       for (int we = i - 1; write < word_start; ++j, --we) s[write++] = s[we];
       for (int ws = word_start, we = i - 1, offset = word_start - write; ws < we; ++ws, --we, write += 2) {
         s[write] = s[we];
         s[we - offset] = s[ws];
       }
     }

     // cout << "STRING SIZE: " << s.size() << endl;
     // cout << "STIRNG NEW SIZE: " << write << endl;
     return s.substr(0, write);
   } */

   // 1. Shrink multiple continuous spaces into one by using the two-pointer
   // technique.
   // 2. Reverse the part of the original string where the spaces were shrunk.
   // This reverses the words in the string, but still maintains the original
   // order of the characters in the words.
   // 3. Reverse each string from left to right. This reverses the characters
   // of each word.
   string reverseWords(string s) {
     int N = s.size(), read, write, space_start;
     for (read = 0, write = 0; read < N;) {
       if (s[read] == ' ') {
         for (space_start = read; read < N and s[read] == ' '; ++read);
         if (read == N) break;
         if (space_start) s[write++] = ' ';
       }
       while (read < N and s[read] != ' ') s[write++] = s[read++];
     }
     reverse(s.begin(), s.begin() + write);
     for (int i = 0, world_start; i < write; ++i) {
       if (s[i] != ' ') {
         for (world_start = i; i < write and s[i] != ' '; ++i);
         reverse(s.begin() + world_start, s.begin() + i);
       }
     }
     return s.substr(0, write);
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
