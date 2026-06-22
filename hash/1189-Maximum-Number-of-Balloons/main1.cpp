#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
    	int c[26]{};
    	for (char ch : text) ++c[ch - 'a'];
    	c['l' - 'a'] /= 2;
    	c['o' - 'a'] /= 2;
    	return min({c['b' - 'a'], c['a' - 'a'], c['l' - 'a'], c['o' - 'a'], c['n' - 'a']});       
    }
};

int main()
{
	Solution s;
	assert(s.maxNumberOfBalloons("nlaebolko") == 1);
	assert(s.maxNumberOfBalloons("loonbalxballpoon") == 2);
	assert(!s.maxNumberOfBalloons("leetcode"));
	return 0;
}
