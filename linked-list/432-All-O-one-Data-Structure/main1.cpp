#include <cassert>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class AllOne {
    struct Bucket { int count; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> where;
public:
    AllOne() = default;
    void inc(string key) {
        unordered_map<string, list<Bucket>::iterator>::iterator it = where.find(key);
        if (it == where.end()) {
            if (buckets.empty() || buckets.front().count != 1) buckets.push_front({1, {}});
            buckets.front().keys.insert(key);
            where[key] = buckets.begin();
            return;
        }
        list<Bucket>::iterator cur = it->second, nxt = next(cur);
        if (nxt == buckets.end() || nxt->count != cur->count + 1) nxt = buckets.insert(nxt, {cur->count + 1, {}});
        nxt->keys.insert(key);
        it->second = nxt;
        cur->keys.erase(key);
        if (cur->keys.empty()) buckets.erase(cur);
    }
    void dec(string key) {
        unordered_map<string, list<Bucket>::iterator>::iterator it = where.find(key);
        list<Bucket>::iterator cur = it->second;
        if (cur->count == 1) where.erase(it);
        else {
            list<Bucket>::iterator prv = cur == buckets.begin() ? buckets.end() : prev(cur);
            if (prv == buckets.end() || prv->count != cur->count - 1) prv = buckets.insert(cur, {cur->count - 1, {}});
            prv->keys.insert(key);
            it->second = prv;
        }
        cur->keys.erase(key);
        if (cur->keys.empty()) buckets.erase(cur);
    }
    string getMaxKey() const { return buckets.empty() ? "" : *buckets.back().keys.cbegin(); }
    string getMinKey() const { return buckets.empty() ? "" : *buckets.front().keys.cbegin(); }
};

int main()
{
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    assert(allOne.getMaxKey() == "hello");
    assert(allOne.getMinKey() == "hello");
    allOne.inc("leet");
    assert(allOne.getMaxKey() == "hello");
    assert(allOne.getMinKey() == "leet");
    return 0;
}
