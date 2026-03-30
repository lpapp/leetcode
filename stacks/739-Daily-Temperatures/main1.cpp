#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const size_t n = temperatures.size();
        stack<size_t> s;
        vector<int> result(n);
        for (int i = n - 1; i >= 0; s.push(i--)) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) s.pop();
            if (!s.empty()) result[i] = s.top() - i;
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
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
	printVector(s.dailyTemperatures(temperatures1));
    vector<int> temperatures2 = {30, 40, 50, 60};
    printVector(s.dailyTemperatures(temperatures2));
    vector<int> temperatures3 = {30, 60, 90};
    printVector(s.dailyTemperatures(temperatures3));
	return 0;
}
