#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int result = hash[s.back()];
        for (size_t i = 0; i < s.size() - 1; ++i) result += (hash[s[i]] < hash[s[i + 1]] ? -1 : 1) * hash[s[i]];
        return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.romanToInt("III") << endl;
	cout << solution.romanToInt("LVIII") << endl;
	cout << solution.romanToInt("MCMXCIV") << endl;
	return 0;
}
