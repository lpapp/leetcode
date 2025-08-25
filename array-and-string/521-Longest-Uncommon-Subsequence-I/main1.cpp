#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
		return a == b ? -1 : max(a.size(), b.size());
    }
};

int main()
{
	Solution solution;
	cout << solution.findLUSlength("aaa", "cdc") << endl;
	cout << solution.findLUSlength("aaa", "bbb") << endl;
	cout << solution.findLUSlength("aaa", "aaa") << endl;
	
	return 0;
}
