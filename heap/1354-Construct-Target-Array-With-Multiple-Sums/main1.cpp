#include <cassert>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = reduce(target.cbegin(), target.cend(), 0LL);
        for (priority_queue<long long> pq(target.cbegin(), target.cend()); pq.top() > 1;) {
            const long long largest = pq.top(), rest = sum - largest; pq.pop();
            if (rest < 1 || largest - rest < 1) return false;
            const long long previous = largest % rest ? largest % rest : rest;
            pq.push(previous);
            sum = rest + previous;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> target1 = {9, 3, 5};
    assert(s.isPossible(target1));
    vector<int> target2 = {1, 1, 1, 2};
    assert(!s.isPossible(target2));
    vector<int> target3 = {8, 5};
    assert(s.isPossible(target3));
    return 0;
}
