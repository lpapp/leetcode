#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> s;
        int prev = 0;
        for (const string& log : logs) {
            int function, time;
            char action[10];
            sscanf(log.c_str(), "%d:%[^:]:%d", &function, action, &time);
            if (action[0] == 's') {
                if (!s.empty()) { const int top = s.top(); result[top] += time - prev; }
                s.push(function);
                prev = time;
            } else {
                const int top = s.top(); s.pop();
                result[top] += time - prev + 1;
                prev = time + 1;
            }
        }
        return result;
    }
};

void printVector(vector<int> input)
{
    for (const int item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
    vector<string> logs1 = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
	printVector(s.exclusiveTime(2, logs1));
    vector<string> logs2 = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
	printVector(s.exclusiveTime(1, logs2));
    vector<string> logs3 = {"0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"};
	printVector(s.exclusiveTime(2, logs3));
	return 0;
}
