#include <array>
#include <iostream>

using namespace std;

class MyHashMap {
	array<int, 1000001> hash;
public:
    MyHashMap() { hash.fill(-1); }
    void put(int key, int value) { hash[key] = value; }
    int get(int key) { return hash[key]; }
    void remove(int key) { hash[key] = -1; }
};

int main()
{
	MyHashMap* myHashMap = new MyHashMap();
	myHashMap->put(1, 1);
	myHashMap->put(2, 2);
	cout << myHashMap->get(1) << endl;
	cout << myHashMap->get(3) << endl;
	myHashMap->put(2, 1);
	cout << myHashMap->get(2) << endl;
	myHashMap->remove(2);
	cout << myHashMap->get(2) << endl;
	return 0;
}
