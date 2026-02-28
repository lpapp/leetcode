#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        size_t writeIndex = 0;
        for (size_t charsLength = chars.size(), readIndex = 0, nextIndex = readIndex + 1; readIndex < charsLength; readIndex = nextIndex) {
            while (nextIndex < charsLength && chars[nextIndex] == chars[readIndex]) ++nextIndex;
          
            chars[writeIndex++] = chars[readIndex];
            const size_t groupSize = nextIndex - readIndex;
            if (groupSize > 1) {
                string countStr = to_string(groupSize);
                for (const char digit : countStr) chars[writeIndex++] = digit;
            }
        }
      
        return writeIndex;
    }
};

int main()
{
	Solution s;
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << s.compress(chars1) << endl;
    vector<char> chars2 = {'a'};
    cout << s.compress(chars2) << endl;
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << s.compress(chars3) << endl;
	return 0;
}
