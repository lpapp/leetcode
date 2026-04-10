#include <array>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        const array<string, 8> digitToLetters = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> result = {""};
        for (const char digit : digits) {
            const string letters = digitToLetters[digit - '2'];
            vector<string> combinations;
            for (const string& combination : result) { for (const char letter : letters) combinations.push_back(combination + letter); }
            result = std::move(combinations);
        }
        return result;      
    }
};

void printVector(vector<string> input)
{
    for (const string& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
    Solution s;
    printVector(s.letterCombinations("23"));
    printVector(s.letterCombinations("2"));
    return 0;
}
