#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    static constexpr int HASH_BASE = 131;
    static constexpr int HASH_MOD = 1000000007;
    static constexpr size_t MAX_LENGTH = 310;
  
    vector<long long> powerBase;
  
    bool isPalindromeConcatenation(int firstIdx, int secondIdx, int secondWordLen, 
                                   int firstWordLen, const vector<long long>& forwardHash, 
                                   const vector<long long>& reverseHash) {
        const long long concatenatedForwardHash = ((forwardHash[firstIdx] * powerBase[secondWordLen]) % HASH_MOD 
                                            + forwardHash[secondIdx]) % HASH_MOD;
        const long long concatenatedReverseHash = ((reverseHash[secondIdx] * powerBase[firstWordLen]) % HASH_MOD 
                                            + reverseHash[firstIdx]) % HASH_MOD;
        return concatenatedForwardHash == concatenatedReverseHash;
    }
  
    void initializePowerBase() {
        powerBase.resize(MAX_LENGTH);
        powerBase[0] = 1;
        for (size_t i = 1; i < MAX_LENGTH; ++i) powerBase[i] = (powerBase[i - 1] * HASH_BASE) % HASH_MOD;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        initializePowerBase();
        const int wordCount = words.size();
        vector<long long> forwardHash(wordCount, 0);
        vector<long long> reverseHash(wordCount, 0);
        for (int i = 0; i < wordCount; ++i) {
            const string& currentWord = words[i];
            const int wordLength = currentWord.length();
            for (int j = 0; j < wordLength; ++j) {
                const int forwardChar = currentWord[j] - 'a' + 1;
                const int reverseChar = currentWord[wordLength - j - 1] - 'a' + 1;
                forwardHash[i] = (forwardHash[i] * HASH_BASE) % HASH_MOD + forwardChar;
                reverseHash[i] = (reverseHash[i] * HASH_BASE) % HASH_MOD + reverseChar;
            }
        }
      
        vector<vector<int>> result;
        for (int i = 0; i < wordCount; ++i) {
            for (int j = i + 1; j < wordCount; ++j) {
                if (isPalindromeConcatenation(i, j, words[j].length(), words[i].length(), 
                                             forwardHash, reverseHash)) {
                    result.push_back({i, j});
                }
                if (isPalindromeConcatenation(j, i, words[i].length(), words[j].length(), 
                                             forwardHash, reverseHash)) {
                    result.push_back({j, i});
                }
            }
        }
      
        return result;
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int& i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<string> words1 = {"abcd", "dcba", "lls", "s", "sssll"};
    printVectorVector(s.palindromePairs(words1));
    vector<string> words2 = {"bat", "tab", "cat"};
    printVectorVector(s.palindromePairs(words2));
    vector<string> words3 = {"a", ""};
    printVectorVector(s.palindromePairs(words3));
	return 0;
}
