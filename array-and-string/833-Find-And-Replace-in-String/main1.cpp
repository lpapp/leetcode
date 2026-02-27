#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        const size_t stringLength = s.size();
        vector<int> mappingArray(stringLength, -1);
        for (size_t operationIndex = 0; operationIndex < indices.size(); ++operationIndex) {
            const size_t startPosition = indices[operationIndex];
            const string source = sources[operationIndex];
            const size_t sourceLength = sources[operationIndex].size();
            if (!s.compare(startPosition, sourceLength, source)) {
                mappingArray[startPosition] = operationIndex;
            }
        }
      
        string result;
        for (size_t currentPosition = 0; currentPosition < stringLength; ++currentPosition) {
            if (mappingArray[currentPosition] != -1) {
                size_t operationIndex = mappingArray[currentPosition];
                result += targets[operationIndex];
                currentPosition += sources[operationIndex].size() - 1;
            } else {
                result += s[currentPosition];
            }
        }
      
        return result;
    }
};

int main()
{
	Solution s;
    vector<int> indices1{0, 2};
    vector<string> sources1{"a", "cd"};
    vector<string> targets1{"eee", "ffff"};
    cout << s.findReplaceString("abcd", indices1, sources1, targets1) << endl;

    vector<int> indices2{0, 2};
    vector<string> sources2{"ab","ec"};
    vector<string> targets2{"eee", "ffff"};
    cout << s.findReplaceString("abcd", indices2, sources2, targets2) << endl;
	return 0;
}
