#include <cassert>
#include <unordered_map>

using namespace std;

class LRUCache {
    struct Node {
        int key, value;
        Node* prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    int size, maxCapacity;
    Node* dummyHead, *dummyTail;
    unordered_map<int, Node*> hash;
    void remove(Node* node) { node->prev->next = node->next; node->next->prev = node->prev; }
    void prepend(Node* node) { node->next = dummyHead->next; node->prev = dummyHead; dummyHead->next->prev = node; dummyHead->next = node; }
public:
    LRUCache(int capacity) : size(0), maxCapacity(capacity), dummyHead(new Node(0, 0)), dummyTail(new Node(0, 0)) { dummyHead->next = dummyTail; dummyTail->prev = dummyHead; }
    int get(int key) { if (!hash.contains(key)) { return -1; } Node* node = hash[key]; remove(node); prepend(node); return node->value; }
    void put(int key, int value) {
        if (hash.contains(key)) { Node* node = hash[key]; remove(node); node->value = value; prepend(node); } 
        else { Node* newNode = new Node(key, value); hash[key] = newNode; prepend(newNode); ++size; if (size > maxCapacity) { Node* lruNode = dummyTail->prev; hash.erase(lruNode->key); remove(lruNode); delete lruNode; --size; } }
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
