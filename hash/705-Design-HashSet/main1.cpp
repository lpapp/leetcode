#include <array>
#include <iostream>

using namespace std;

class MyHashSet {
	array<bool, 1000001> hash;
public:
    MyHashSet() = default;
    void add(int key) { hash[key] = true; }
    void remove(int key) { hash[key] = false; }
    bool contains(int key) { return hash[key]; }
};

int main()
{
	MyHashSet* myHashSet = new MyHashSet();
	myHashSet->add(1);
	myHashSet->add(2);
 	cout << myHashSet->contains(1) << endl;
	cout << myHashSet->contains(3) << endl;
	myHashSet->add(2);
	cout << myHashSet->contains(2) << endl;
	myHashSet->remove(2);
	cout << myHashSet->contains(2) << endl;
	return 0;
}
