#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) if (c >= 'A' && c <= 'Z') c |= 32;
        return s;
    }
};

int main()
{
	Solution s;
    cout << s.toLowerCase("Hello") << endl;
    cout << s.toLowerCase("here") << endl;
    cout << s.toLowerCase("LOVELY") << endl;
	return 0;
}
