#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i]; digits[i] %= 10;
            if (digits[i]) return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
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
    vector<int> digits1 = {1, 2, 3};
    printVector(s.plusOne(digits1));
    vector<int> digits2 = {4, 3, 2, 1};
    printVector(s.plusOne(digits2));
    vector<int> digits3 = {9};
    printVector(s.plusOne(digits3));
	return 0;
}
