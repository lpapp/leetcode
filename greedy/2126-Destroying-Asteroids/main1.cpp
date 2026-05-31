#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;


class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        uint64_t current = mass;
        for (const uint64_t asteroid : asteroids) {
            if (current < asteroid) return false;
            current += asteroid;
        }
        return true;
    }
};

int main()
{
	Solution s;
    vector<int> asteroids1 = {3, 9, 19, 5, 21};
    assert(s.asteroidsDestroyed(10, asteroids1));
    vector<int> asteroids2 = {4, 9, 23, 4};
    assert(!s.asteroidsDestroyed(5, asteroids2));
	return 0;
}
