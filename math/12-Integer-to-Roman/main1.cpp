#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<string, int>> romans = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
        string result;
        for (const auto& [roman, i] : romans) for (; num >= i; num -= i, result += roman);
        return result;   
    }
};

int main()
{
	Solution solution;
	cout << solution.intToRoman(3749) << endl;
	cout << solution.intToRoman(58) << endl;
	cout << solution.intToRoman(1994) << endl;
	return 0;
}
