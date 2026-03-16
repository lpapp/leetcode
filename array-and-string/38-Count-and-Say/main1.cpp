#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (string next; --n; result = next) {
            next = "";
            for (size_t i = 0, j = 0; i < result.size(); i = j) {
                for (; j < result.size() && result[j] == result[i]; ++j);
                next += to_string(j - i);
                next += result[i];
            }
        }
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(1) << endl;
	return 0;
}
