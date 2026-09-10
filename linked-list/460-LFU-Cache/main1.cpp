#include <cassert>
#include <list>
#include <unordered_map>

using namespace std;

class LFUCache {
    struct Entry {
        list<pair<int, int>>::iterator it;
        int freq;
    };
    const int capacity;
    int minFreq = 0;
    unordered_map<int, Entry> cache;
    unordered_map<int, list<pair<int, int>>> freqList;
    void touch(int key, int value) {
        Entry& entry = cache[key];
        list<pair<int, int>>& oldList = freqList[entry.freq];
        oldList.erase(entry.it);
        if (oldList.empty() && entry.freq == minFreq) ++minFreq;
        ++entry.freq;
        freqList[entry.freq].emplace_front(key, value);
        entry.it = freqList[entry.freq].begin();
    }
public:
    LFUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) return -1;
        const int value = it->second.it->second;
        touch(key, value);
        return value;
    }
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) { touch(key, value); return; }
        if (static_cast<int>(cache.size()) == capacity) {
            list<pair<int, int>>& minList = freqList[minFreq];
            cache.erase(minList.back().first);
            minList.pop_back();
        }
        freqList[1].emplace_front(key, value);
        cache[key] = {freqList[1].begin(), 1};
        minFreq = 1;
    }
};

int main()
{
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    assert(lfu.get(1) == 1);
    lfu.put(3, 3);
    assert(lfu.get(2) == -1);
    assert(lfu.get(3) == 3);
    lfu.put(4, 4); 
    assert(lfu.get(1) == -1);
    assert(lfu.get(3) == 3);
    assert(lfu.get(4) == 4);
    return 0;
}
