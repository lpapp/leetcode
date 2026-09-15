#include <cassert>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> idx;
    mt19937 rng{random_device{}()};
public:
    RandomizedSet() { vals.reserve(200000); idx.reserve(200000); }
    bool insert(int val) {
        auto [it, inserted] = idx.try_emplace(val, vals.size());
        if (!inserted) return false;
        vals.push_back(val);
        return true;
    }
    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end()) return false;
        const int i = it->second, last = vals.back();
        vals[i] = last;
        idx[last] = i;
        vals.pop_back();
        idx.erase(it);
        return true;
    }
    int getRandom() { return vals[uniform_int_distribution<int>(0, vals.size() - 1)(rng)]; }
};

int main()
{
    RandomizedSet randomizedSet;
    assert(randomizedSet.insert(1));
    assert(!randomizedSet.remove(2));
    assert(randomizedSet.insert(2));
    int res1 = randomizedSet.getRandom();
    assert(res1 == 1 || res1 == 2);
    assert(randomizedSet.remove(1));
    assert(!randomizedSet.insert(2));
    assert(randomizedSet.getRandom() == 2);
    return 0;
}
