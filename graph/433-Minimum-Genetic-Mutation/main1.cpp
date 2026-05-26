#include <cassert>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> visited({startGene});
        for (queue<pair<string, int>> q({{startGene, 0}}); !q.empty(); ) {
            const auto [current, count] = q.front(); q.pop();
            if (current == endGene) return count;
            for (const string& candidate : bank) {
                int diff = 2;
                for (int position = 0; position < 8 && diff > 0; ++position) if (current[position] != candidate[position]) --diff;
                if (diff == 1 && !visited.contains(candidate)) {
                    visited.insert(candidate);
                    q.push({candidate, count + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<string> bank1 = {"AACCGGTA"};
    assert(s.minMutation("AACCGGTT", "AACCGGTA", bank1) == 1);
    vector<string> bank2 = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    assert(s.minMutation("AACCGGTT", "AAACGGTA", bank2) == 2);
    return 0;
}
