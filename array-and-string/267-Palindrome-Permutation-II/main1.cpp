#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    void dfs(string currentPalindrome, size_t sLength, vector<string>& result, unordered_map<char, int>& charFrequency) {
        if (currentPalindrome.size() == sLength) {
            result.push_back(currentPalindrome);
            return;
        }

        for (auto& [character, frequency] : charFrequency) {
            if (frequency > 1) {
                frequency -= 2;
                dfs(character + currentPalindrome + character, sLength, result, charFrequency);
                frequency += 2;
            }
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> charFrequency;
        for (const char c : s) ++charFrequency[c];
        string middleChar = "";
        for (const auto& [character, frequency] : charFrequency) {
            if (frequency & 1) {
                if (middleChar != "") return {};
                middleChar += character;
            }
        }

        const size_t sLength = s.size();
        vector<string> result;
        dfs(middleChar, sLength, result, charFrequency);
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
    printVector(s.generatePalindromes("aab"));
    printVector(s.generatePalindromes("abc"));
    printVector(s.generatePalindromes("aabb"));
	return 0;
}
