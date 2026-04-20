#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;
    string find(string variable) {
        if (parent[variable] != variable) {
            string originalParent = parent[variable];
            parent[variable] = find(parent[variable]);
            weight[variable] *= weight[originalParent];
        }
        return parent[variable];
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (const vector<string>& equation : equations) {
            parent[equation[0]] = equation[0];
            parent[equation[1]] = equation[1];
            weight[equation[0]] = 1.0;
            weight[equation[1]] = 1.0;
        }
        for (size_t i = 0, equationsLength = equations.size(); i < equationsLength; ++i) {
            vector<string> equation = equations[i];
            string numerator = equation[0];
            string denominator = equation[1];
            string parentNumerator = find(numerator);
            string parentDenominator = find(denominator);
            if (parentNumerator == parentDenominator) continue;
            parent[parentNumerator] = parentDenominator;
            weight[parentNumerator] = weight[denominator] * values[i] / weight[numerator];
        }
        const size_t queriesLength = queries.size();
        vector<double> result(queriesLength);
        for (size_t i = 0; i < queriesLength; ++i) {
            string dividend = queries[i][0], divisor = queries[i][1];
            if (parent.find(dividend) == parent.end() || parent.find(divisor) == parent.end() || find(dividend) != find(divisor)) result[i] = -1.0;
            else result[i] = weight[dividend] / weight[divisor];
        }
        return result;
    }
};

void printVector(vector<double> input)
{
    for (const double item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
    Solution s;
	vector<vector<string>> equations1 = {
		{"a", "b"},
		{"b", "c"}
	};
	vector<double> values1 = {2.0, 3.0};
	vector<vector<string>> queries1 = {
		{"a", "c"},
		{"b", "a"},
		{"a", "e"},
		{"a", "a"},
		{"x", "x"}
	};
	printVector(s.calcEquation(equations1, values1, queries1));
	vector<vector<string>> equations2 = {
		{"a", "b"},
		{"b", "c"},
		{"bc", "cd"}
	};
	vector<double> values2 = {1.5, 2.5, 5.0};
	vector<vector<string>> queries2 = {
        {"a", "c"},
        {"c", "b"},
        {"bc", "cd"},
        {"cd", "bc"}
	};
	printVector(s.calcEquation(equations2, values2, queries2));
	vector<vector<string>> equations3 = {
		{"a", "b"},
	};
	vector<double> values3 = {0.5};
	vector<vector<string>> queries3 = {
        {"a", "b"},
        {"b", "a"},
        {"a", "c"},
        {"x", "y"}
	};
	printVector(s.calcEquation(equations3, values3, queries3));
    return 0;
}
