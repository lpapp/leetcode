#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (int asteroid : asteroids) {
            while (!s.empty() && asteroid < 0 && s.back() > 0) {
                int diff = s.back() + asteroid;
                if (diff < 0) s.pop_back();
                else if (diff > 0) { asteroid = 0; break; }
                else { s.pop_back(); asteroid = 0; break; }
            }
            if (asteroid) s.push_back(asteroid);
        }
        return s;   
    }
};

int main()
{
	Solution s;
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> res1 = {5, 10};
	assert(s.asteroidCollision(asteroids1) == res1);
    vector<int> asteroids2 = {8, -8};
    vector<int> res2 = {};
	assert(s.asteroidCollision(asteroids2) == res2);
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> res3 = {10};
	assert(s.asteroidCollision(asteroids3) == res3);
    vector<int> asteroids4 = {3, 5, -6, 2, -1, 4};
    vector<int> res4 = {-6, 2, 4};
	assert(s.asteroidCollision(asteroids4) == res4);
	return 0;
}
