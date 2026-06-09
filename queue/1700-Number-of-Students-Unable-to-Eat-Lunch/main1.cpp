#include <array>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        array<int, 2> hash = {0};
        for (const int student : students) ++hash[student];
        for (const int sandwich : sandwiches) if (!hash[sandwich]--) return hash[sandwich ^ 1];
        return 0;       
    }
};

int main()
{
	Solution s;
    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};
    assert(!s.countStudents(students1, sandwiches1));
    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    assert(s.countStudents(students2, sandwiches2) == 3);
	return 0;
}
