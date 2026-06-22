#include <cassert>
#include <queue>

using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() = default;
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) q.pop();
        return q.size();   
    }
};

int main()
{
    RecentCounter* recentCounter = new RecentCounter();
    assert(recentCounter->ping(1) == 1);
    assert(recentCounter->ping(100) == 2);
    assert(recentCounter->ping(3001) == 3);
    assert(recentCounter->ping(3002) == 3);
	return 0;
}
