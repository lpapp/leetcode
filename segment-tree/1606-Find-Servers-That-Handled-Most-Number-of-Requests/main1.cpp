#include <algorithm>
#include <bit>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        const int size = bit_ceil((unsigned)k);
        vector<int> tree(2 * size, INT_MAX), count(k), res;
        ranges::fill_n(tree.begin() + size, k, 0);
        for (int node = size - 1; node; --node) tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        const auto find = [&](int node, const int time) {
            for (node += size; tree[node] > time; ++node) {
                while (node & 1) node >>= 1;
                if (!node) return -1;
            }
            while (node < size) node = 2 * node + (tree[2 * node] > time);
            return node - size;
        };
        for (int request = 0, n = arrival.size(); request < n; ++request) {
            const int time = arrival[request];
            if (tree[1] > time) continue;
            int server = find(request % k, time);
            if (server < 0) server = find(0, time);
            ++count[server];
            tree[server + size] = time + load[request];
            for (int node = (server + size) >> 1; node; node >>= 1) tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
        const int most = ranges::max(count);
        for (int server = 0; server < k; ++server) if (count[server] == most) res.push_back(
server);
        return res;       
    }
};

int main()
{
    Solution s;
    vector<int> arrival1 = {1, 2, 3, 4, 5};
    vector<int> load1 = {5, 2, 3, 3, 3};
    vector<int> res1 = {1};
    assert(s.busiestServers(3, arrival1, load1) == res1);
    vector<int> arrival2 = {1, 2, 3, 4};
    vector<int> load2 = {1, 2, 1, 2};
    vector<int> res2 = {0};
    assert(s.busiestServers(3, arrival2, load2) == res2);
    vector<int> arrival3 = {1, 2, 3};
    vector<int> load3 = {10, 12, 11};
    vector<int> res3 = {0, 1, 2};
    assert(s.busiestServers(3, arrival3, load3) == res3);
    return 0;
}
