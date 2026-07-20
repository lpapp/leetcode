#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int n;
    vector<vector<pair<int, int>>> adj;
public:
    Graph(int n, vector<vector<int>>& edges) : n(n), adj(n) { for (vector<int>& e : edges) adj[e[0]].emplace_back(e[1], e[2]); }
    void addEdge(vector<int> edge) { adj[edge[0]].emplace_back(edge[1], edge[2]); }
    int shortestPath(int node1, int node2) {
        vector<int> dist(n, INT_MAX); dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; pq.emplace(0, node1);
        while (!pq.empty()) {
            const auto [d, u] = pq.top(); pq.pop();
            if (u == node2) return d;
            if (d > dist[u]) continue;
            for (const auto [v, w] : adj[u]) if (dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.emplace(dist[v], v); }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> edges1 = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    Graph* g = new Graph(4, edges1);
    assert(g->shortestPath(3, 2) == 6);
    assert(g->shortestPath(0, 3) == -1);
    g->addEdge({1, 3, 4}); 
    assert(g->shortestPath(0, 3) == 6);
    return 0;
}
