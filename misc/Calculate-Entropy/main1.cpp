#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    double calculateEntropy(vector<int>& input) {
        unordered_map<int, int> hash;                                             
        for (const int i : input) ++hash[i];
        double result = 0, n = input.size();                                     
        for (const auto [_, count] : hash) { const double p = count / n; result -= p * log2(p); }
        return result;
    }
};

int main()
{
	Solution s;
    vector<int> input = {1, 1, 2, 2};
    cout << s.calculateEntropy(input) << endl;
	return 0;
}
