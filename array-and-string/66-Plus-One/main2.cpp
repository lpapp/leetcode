#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      for (int N = digits.size(), i = N - 1; i >= 0; digits[i] = 0, --i) if (digits[i] < 9) { ++digits[i]; return digits; };
      digits[0] = 1; digits.push_back(0);                                       
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
