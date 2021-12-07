#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString_two_pointer(vector<char>& s) {
      for (size_t start = 0, end = s.size() - 1; start < end; ++start, --end) swap(s[start], s[end]);
    }

    void reverseString(vector<char>& s) {
      for (size_t i = 0, li = s.size() - 1; i < s.size() / 2; ++i) swap(s[i], s[li - i]);
    }
};

void test(vector<char>& s)
{
  Solution solution;
  solution.reverseString(s);

  cout << "[";
  for (const char e : s) cout << e << ",";
  cout << "]" << endl;
}

int main()
{
  vector<char> A1{'h', 'e', 'l', 'l', 'o'};
  cout << "['h','e','l','l','o'] => ['o','l','l','e','h']: ";
  test(A1);

  vector<char> A2{'H', 'a', 'n', 'n', 'a', 'h'};
  cout << "['H','a','n','n','a','h'] => ['h','a','n','n','a','H']: ";
  test(A2);

  vector<char> A3{'a'};
  cout << "['a'] => ['a']: ";
  test(A3);

  vector<char> A4{'h', 'e', 'l', 'l'};
  cout << "['h','e','l','l'] => ['l','l','e','h']: ";
  test(A4);


  return 0;
}
