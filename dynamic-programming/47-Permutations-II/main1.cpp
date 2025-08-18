#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<int, int> buildFrequencyTable(vector<int>& nums) {
        unordered_map<int, int> result;
        for (const int item : nums) ++result[item];
        return result;
    }

    void printPerms(unordered_map<int, int> hash, vector<int>& prefix, int remaining, vector<vector<int>>& result) {
        // Base case. The permutation has been completed.
        if (!remaining) { result.push_back(prefix); return; }

        // Try the remaining integers for the next integer and generate the remaining permutations.
        for (const auto [item, frequency] : hash) {
            if (frequency > 0) {
                hash[item] = frequency - 1;
                prefix.push_back(item);
                printPerms(hash, prefix, remaining - 1, result);
                prefix.pop_back(); 
                hash[item] = frequency;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> hash = buildFrequencyTable(nums);
        vector<int> prefix;
        printPerms(hash, prefix, nums.size(), result);
        return result;
    }
};

void printSolution(vector<vector<int>> input)
{
    cout << "[";
    for (const vector<int>& vectorItem : input) {
        cout << "[";
        for (const int item : vectorItem) cout << item << ", ";
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

int main()
{
	Solution solution;

	vector<int> input1 = {1, 1, 2};
	printSolution(solution.permuteUnique(input1));

	vector<int> input2 = {1, 2, 3};
	printSolution(solution.permuteUnique(input2));

	return 0;
}
