#include <cassert>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    const int capacity;
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) return -1;
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }
        if (static_cast<int>(cache.size()) == capacity) {
            cache.erase(order.back().first);
            order.pop_back();
        }
        order.emplace_front(key, value);
        cache[key] = order.begin();
    }
};

int main()
{
	LRUCache* cache = new LRUCache(2);
	cache->put(1, 1);
	cache->put(2, 2);
	assert(cache->get(1) == 1);
	cache->put(3, 3);
	assert(cache->get(2) == -1);
	cache->put(4, 4);
	assert(cache->get(1) == -1);
	assert(cache->get(3) == 3);
	assert(cache->get(4) == 4);
	return 0;
}
