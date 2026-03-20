#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
      for (size_t i = 0, li = s.size() - 1; i < s.size() / 2; ++i) swap(s[i], s[li - i]);
    }
};

void printVector(vector<char>& input)
{
    for (const char item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(s1);
    printVector(s1);

    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    s.reverseString(s2);
    printVector(s2);
	return 0;
}
