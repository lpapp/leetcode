#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Runtime Complexity: O(k * (n + m)
//
// Space complexity:   O(n)
//
// n: number of the cities
// k: the number of maximum stops
// m: the number of flights

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        constexpr int maxPrice = std::numeric_limits<int>::max();
        std::vector<int> distances(n, maxPrice);
        std::vector<int> previousIterationDistances;
        distances[src] = 0;

        // Bellman-Ford algorithm
        // k + 1 nodes for k intermediate
        for (int i = 0; i < k + 1; ++i) {
            previousIterationDistances = distances;
            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                if (previousIterationDistances[from] < maxPrice) {
                    distances[to] = min(distances[to], previousIterationDistances[from] + price);
                }
            }
        }

        return distances[dst] == maxPrice ? -1 : distances[dst];       
    }
};


int main()
{
  Solution solution;
  std::vector<std::vector<int>> i1{
    {0, 1, 100},
    {1, 2, 100},
    {2, 0, 100},
    {1, 3, 600},
    {2, 3, 200}
  };

  std::cout << solution.findCheapestPrice(4, i1, 0, 3, 1) << std::endl;

  return 0;
}
