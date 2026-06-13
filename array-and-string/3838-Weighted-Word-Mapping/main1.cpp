#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        const int n = words.size();
        string res(n, ' ');
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (char c : words[i]) s += weights[c - 'a'];
            res[i] = 'z' - s % 26;
        }
        return res;      
    }
};

int main()
{
    Solution s;
    vector<string> words1 = {"abcd", "def", "xyz"};
    vector<int> weights1 = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
    assert(s.mapWordWeights(words1, weights1) == "rij");
    vector<string> words2 = {"a", "b", "c"};
    vector<int> weights2 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    assert(s.mapWordWeights(words2, weights2) == "yyy");
    vector<string> words3 = {"abcd"};
    vector<int> weights3 = {7, 5, 3, 4, 3, 5, 4, 9, 4, 2, 2, 7, 10, 2, 5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5};
    assert(s.mapWordWeights(words3, weights3) == "g");
    return 0;
}
