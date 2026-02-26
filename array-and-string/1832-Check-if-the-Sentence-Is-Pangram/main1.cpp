#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> hash;
        for (const char& c: sentence) hash.insert(c);
        return hash.size() == 26;
    }
};

int main()
{
	Solution s;
    cout << s.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << endl;
    cout << s.checkIfPangram("leetcode") << endl;
	return 0;
}
