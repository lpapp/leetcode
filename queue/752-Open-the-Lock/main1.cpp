#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    vector<string> getNeighbours(string& number) {
        vector<string> neighbours;
        for (size_t i = 0; i < 4; ++i) {
            char digit = number[i];
            number[i] = (digit == '0') ? '9' : (char)(digit - 1);
            neighbours.push_back(number);
            number[i] = (digit == '9') ? '0' : (char)(digit + 1);
            neighbours.push_back(number);
            number[i] = digit;
        }
        return neighbours;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.cbegin(), deadends.cend());
		if (visited.count("0000")) return -1;
		if (target == "0000") return 0;
        queue<string> q{{"0000"}};
        visited.insert("0000");
        int turns = 0;
        while (!q.empty()) {
            ++turns;
            const size_t levelSize = q.size();
            for (size_t i = 0; i < levelSize; ++i) {
                string number = q.front(); q.pop();
                for (const string& neighbour : getNeighbours(number)) {
                    if (neighbour == target) return turns;
                    if (!visited.contains(neighbour)) {
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
	vector<string> deadends1 = {"0201", "0101", "0102", "1212", "2002"};
    cout << s.openLock(deadends1, "0202") << endl;
	vector<string> deadends2 = {"8888"};
    cout << s.openLock(deadends2, "0009") << endl;
	vector<string> deadends3 = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    cout << s.openLock(deadends3, "8888") << endl;
    return 0;
}
