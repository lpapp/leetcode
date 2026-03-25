#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Logger {
    std::unordered_map<std::string, int> hash;
public:
    Logger() = default;
    bool shouldPrintMessage(int timestamp, string message) {
        if (hash.contains(message) && hash[message] > timestamp) return false;
        hash[message] = timestamp + 10;
        return true;
    }
};

int main()
{
	Logger l;
    cout << l.shouldPrintMessage(1, "foo") << endl;
    cout << l.shouldPrintMessage(2, "bar") << endl;
    cout << l.shouldPrintMessage(3, "foo") << endl;
    cout << l.shouldPrintMessage(8, "bar") << endl;
    cout << l.shouldPrintMessage(11, "foo") << endl;
    cout << l.shouldPrintMessage(12, "bar") << endl;
	return 0;
}
