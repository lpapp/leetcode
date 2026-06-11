#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
          priority_queue<int> pq(stones.begin(), stones.end());
          while (pq.size() > 1) {
              int a = pq.top(); pq.pop();
              int b = pq.top(); pq.pop();
              if (a != b) pq.push(a - b);
          }
          return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    Solution s;
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    assert(s.lastStoneWeight(stones1) == 1);
    return 0;
}
