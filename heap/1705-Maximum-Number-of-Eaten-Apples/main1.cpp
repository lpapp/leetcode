#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int ans = 0;
        for (int day = 0, n = days.size(); day < n || !pq.empty(); ++day) {
            if (day < n && apples[day] > 0) pq.emplace(day + days[day], apples[day]);
            while (!pq.empty() && pq.top().first <= day) pq.pop();
            if (!pq.empty()) {
                auto [exp, cnt] = pq.top(); pq.pop();
                ++ans;
                if (--cnt > 0 && exp > day + 1) pq.emplace(exp, cnt);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> apples1 = {1, 2, 3, 5, 2};  
    vector<int> days1 = {3, 2, 1, 4, 2};
    assert(s.eatenApples(apples1, days1) == 7);
    vector<int> apples2 = {3, 0, 0, 0, 0, 2}; 
    vector<int> days2 = {3, 0, 0, 0, 0, 2};
    assert(s.eatenApples(apples2, days2) == 5);
    return 0;
}
