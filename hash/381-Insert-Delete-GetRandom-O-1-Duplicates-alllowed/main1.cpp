#include <cassert>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedCollection {
    vector<pair<int, int>> vals;
    unordered_map<int, vector<int>> idx;
    mt19937 rng{random_device{}()};
public:
    RandomizedCollection() { vals.reserve(200000); idx.reserve(200000); }
    bool insert(int val) {
        vector<int>& pos = idx[val];
        pos.push_back(vals.size());
        vals.emplace_back(val, pos.size() - 1);
        return pos.size() == 1;
    }
    bool remove(int val) {
        unordered_map<int, vector<int>>::iterator it = idx.find(val);
        if (it == idx.end() || it->second.empty()) return false;
        const int removeAt = it->second.back(), lastAt = vals.size() - 1;
        it->second.pop_back();
        if (removeAt < lastAt) {
            const pair<int, int> last = vals[lastAt];
            vals[removeAt] = last;
            idx[last.first][last.second] = removeAt;
        }
        vals.pop_back();
        if (it->second.empty()) idx.erase(it);
        return true;
    }
    int getRandom() { return vals[uniform_int_distribution<int>(0, vals.size() - 1)(rng)].first; }
};

int main()
{
    RandomizedCollection randomizedCollection;
    assert(randomizedCollection.insert(1));
    assert(!randomizedCollection.insert(1));
    assert(randomizedCollection.insert(2));
    const int res1 = randomizedCollection.getRandom();
    assert(res1 == 1 || res1 == 2);
    assert(randomizedCollection.remove(1));
    const int res2 = randomizedCollection.getRandom();
    assert(res2 == 1 || res2 == 2);
    return 0;
}
