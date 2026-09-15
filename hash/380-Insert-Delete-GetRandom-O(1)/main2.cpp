#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
    unordered_map<int, size_t> hash;
    vector<int> vals;
public:
    RandomizedSet() = default;
    bool insert(int val) { if (hash.contains(val)) return false; hash[val] = vals.size(); vals.push_back(val); return true; }
    bool remove(int val) { if (!hash.contains(val)) return false; const size_t index = hash[val]; const int last = vals.back(); vals[index] = last, vals.pop_back(); hash[last] = index, hash.erase(val); return true;   }
    int getRandom() { return vals[rand() % vals.size()]; }
};

int main()
{
    RandomizedSet* randomizedSet = new RandomizedSet();
    cout << randomizedSet->insert(1) << endl;
    cout << randomizedSet->remove(2) << endl;
    cout << randomizedSet->insert(2) << endl;
    cout << randomizedSet->getRandom() << endl;
    cout << randomizedSet->remove(1) << endl;
    cout << randomizedSet->insert(2) << endl;
    cout << randomizedSet->getRandom() << endl;
	return 0;
}
