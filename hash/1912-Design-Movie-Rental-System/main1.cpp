#include <cassert>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class MovieRentingSystem {
    unordered_map<long long, int> price;
    unordered_map<int, set<pair<int, int>>> avail;
    set<tuple<int, int, int>> rented;
    long long key(int shop, int movie) const { return static_cast<long long>(shop) * 10001 + movie; }
public:
    MovieRentingSystem([[maybe_unused]] int n, vector<vector<int>>& entries) { for (const vector<int>& e : entries) { price[key(e[0], e[1])] = e[2]; avail[e[1]].emplace(e[2], e[0]); } }
    vector<int> search(int movie) { vector<int> res; unordered_map<int, set<pair<int, int>>>::iterator it = avail.find(movie); if (it == avail.end()) return res; for (const pair<int, int>& p : it->second) { res.push_back(p.second); if (res.size() == 5) break; } return res; }
    void rent(int shop, int movie) { const int p = price[key(shop, movie)]; avail[movie].erase({p, shop}); rented.emplace(p, shop, movie); }
    void drop(int shop, int movie) { const int p = price[key(shop, movie)]; rented.erase({p, shop, movie}); avail[movie].emplace(p, shop); }
    vector<vector<int>> report() { vector<vector<int>> res; for (const auto& [_, shop, movie] : rented) { res.push_back({shop, movie}); if (res.size() == 5) break; } return res; }
};

int main()
{
    vector<vector<int>> entries1 = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
    MovieRentingSystem movieRentingSystem(3, entries1);
    vector<int> res1 = {1, 0, 2};
    assert(movieRentingSystem.search(1) == res1);
    movieRentingSystem.rent(0, 1);
    movieRentingSystem.rent(1, 2);
    vector<vector<int>> res2 = {{0, 1}, {1, 2}};
    assert(movieRentingSystem.report() == res2);
    movieRentingSystem.drop(1, 2);
    vector<int> res3 = {0, 1};
    assert(movieRentingSystem.search(2) == res3);
    return 0;
}
