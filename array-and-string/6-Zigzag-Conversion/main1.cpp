#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string result;
        for (int row = 0, sLength = s.size(), diff = 2 * (numRows - 1); row < numRows; ++row) for (int i = row; i < sLength; i += diff) { result += s[i]; if (row > 0 && row < numRows - 1 && i + diff - 2 * row < sLength) result += s[i + diff - 2 * row]; }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << s.convert("A", 1) << endl;
    return 0;
}
