#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        const int serverCount = servers.size(), taskCount = tasks.size();
        constexpr long long MASK = (1 << 18) - 1;
        vector<long long> keys(serverCount);
        for (int i = 0; i < serverCount; ++i) keys[i] = (long long)servers[i] << 18 | i;
        ranges::sort(keys);
        vector<unsigned long long> low((serverCount + 63) / 64), middle((low.size() + 63) / 
64);
        unsigned long long high = 0;
        const auto release = [&](const int rank) { low[rank >> 6] |= 1ULL << (rank & 63); middle[rank >> 12] |= 1ULL << (rank >> 6 & 63); high |= 1ULL << (rank >> 12); };
        const auto acquire = [&] {
            const int top = countr_zero(high), block = top << 6 | countr_zero(middle[top]), 
rank = block << 6 | countr_zero(low[block]);
            if (!(low[block] &= low[block] - 1) && !(middle[top] &= middle[top] - 1)) high &= high - 1;
            return rank;
        };
        for (int rank = 0; rank < serverCount; ++rank) release(rank);
        priority_queue<long long, vector<long long>, greater<long long>> busy;
        vector<int> res(taskCount);
        for (int time = 0; time < taskCount; ++time) {
            for (; !busy.empty() && busy.top() >> 18 <= time; busy.pop()) release(busy.top()
 & MASK);
            if (high) {
                const int rank = acquire();
                busy.push((long long)(time + tasks[time]) << 18 | rank);
                res[time] = keys[rank] & MASK;
            } else {
                const long long top = busy.top();
                busy.pop();
                busy.push(top + ((long long)tasks[time] << 18));
                res[time] = keys[top & MASK] & MASK;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> servers1 = {3, 3, 2};
    vector<int> tasks1 = {1, 2, 3, 2, 1, 2};
    vector<int> res1 = {2, 2, 0, 2, 1, 2};
    assert(s.assignTasks(servers1, tasks1) == res1);
    vector<int> servers2 = {5, 1, 4, 3, 2};
    vector<int> tasks2 = {2, 1, 2, 4, 5, 2, 1};
    vector<int> res2 = {1, 4, 1, 4, 1, 3, 2};
    assert(s.assignTasks(servers2, tasks2) == res2);
    return 0;
}
