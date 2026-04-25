#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int num = 1;
        for (const int targetNum : target) {
            for (;num < targetNum; result.push_back("Push"), result.push_back("Pop"), ++num);
            result.push_back("Push");
            ++num;
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
	vector<int> target1 = {1, 3};
    printVector(s.buildArray(target1, 3));
	vector<int> target2 = {1, 2, 3};
    printVector(s.buildArray(target2, 3));
	vector<int> target3 = {1, 2};
    printVector(s.buildArray(target3, 4));
	return 0;
}
