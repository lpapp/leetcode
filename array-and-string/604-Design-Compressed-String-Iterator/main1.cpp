#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class StringIterator {
    vector<pair<char, int>> characterFrequencies;
    size_t currentIndex{0};
public:
    StringIterator(string compressedString) {
        for (size_t i = 0, compressedStringLength = compressedString.size(); i < compressedStringLength; ) {
            char c = compressedString[i++];
            int frequency = 0;
            for (; i < compressedStringLength && isdigit(compressedString[i]); ++i) frequency = frequency * 10 + (compressedString[i] - '0');
            characterFrequencies.push_back({c, frequency});
        }
    }

    char next() {
        if (!hasNext()) return ' ';
        const char result = characterFrequencies[currentIndex].first;
        characterFrequencies[currentIndex].second--;
        if (!characterFrequencies[currentIndex].second) ++currentIndex;
        return result;
    }

    bool hasNext() {
        return currentIndex < characterFrequencies.size() &&
               characterFrequencies[currentIndex].second > 0;
    }
};

int main()
{
    StringIterator* obj = new StringIterator("L1e2t1C1o1d1e1");
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
	return 0;
}
