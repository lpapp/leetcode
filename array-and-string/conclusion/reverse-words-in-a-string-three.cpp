#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      for (int i = 0, world_start, N = s.size(); i < N; ++i) {
        if (s[i] != ' ') {
          for (world_start = i; i < N and s[i] != ' '; ++i);
          reverse(s.begin() + world_start, s.begin() + i);
        }
      }
      return s;
    }
};

int main()
{
  Solution s;

  string S1 = "Let's take LeetCode contest";
  cout << "'Let's take LeetCode contest' => 's'teL ekat edoCteeL tsetnoc': " << s.reverseWords(S1) << endl;

  string S2 = "God Ding";
  cout << "'God Ding' => 'doG gniD': " << s.reverseWords(S2) << endl;

  string S3 = "God";
  cout << "'God' => 'doG': " << s.reverseWords(S3) << endl;

  return 0;
}
