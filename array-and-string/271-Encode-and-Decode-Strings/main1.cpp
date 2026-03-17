#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Codec {
public:
    string encode(vector<string>& strs) {
        string result;
        for (const string& str : strs) {
            result.append(format("{:4}", str.size()));
            result.append(str);
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        for (size_t i = 0, sLength = s.size(), currentLength = 0; i < sLength; i += currentLength) {
            currentLength = stoi(s.substr(i, 4));
            i += 4;
            result.push_back(s.substr(i, currentLength));
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
    Codec codec;
    vector<string> strs1 = {"Hello", "World"};
    string encoded1 = codec.encode(strs1);
    cout << encoded1 << endl;
    printVector(codec.decode(encoded1));

    vector<string> strs2 = {"Hi", "I'm", "Sam!"};
    string encoded2 = codec.encode(strs2);
    cout << encoded2 << endl;
    printVector(codec.decode(encoded2));

	return 0;
}
