#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            string current = "";
            if (!(i % 3)) current += "Fizz";
            if (!(i % 5)) current += "Buzz";
            if (current.empty()) current= to_string(i);
            result.push_back(current);
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
    printVector(s.fizzBuzz(3));
    printVector(s.fizzBuzz(5));
    printVector(s.fizzBuzz(15));
	return 0;
}
