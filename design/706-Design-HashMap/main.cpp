#include <cstring>
#include <iostream>

using namespace std;

// 'MyHashMap' implements a fixed-size hash map using an array where
// the keys are integers and the values are also integers.
class MyHashMap {
public:
	// Define the size of the data array.
    static constexpr int SIZE = 1000001;

	// Array to store the values mapped by the keys.
    int data[SIZE];

    // Constructor to initialize the hash map (set all values to -1).
    MyHashMap() { memset(data, -1, sizeof(data)); }

    // 'put' method for inserting a key-value pair into the hash map.
    // If the key already exists, it updates its value.
    // @param key The key to insert or update.
    // @param value The value to be associated with the key.
    void put(int key, int value) { data[key] = value; }

    // 'get' method to retrieve the value associated with a key.
    // @param key The key whose value is to be retrieved.
    // @return The value associated with the key, or -1 if the key does not exist.
    int get(int key) { return data[key]; }

    // 'remove' method to delete the value associated with a key.
    // It sets the value at the key index to -1.
    // @param key The key whose value is to be removed.
    void remove(int key) { data[key] = -1; }
};

int main()
{
	MyHashMap myHashMap;
	myHashMap.put(1, 1); // The map is now [[1,1]]
	myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
	cout << myHashMap.get(1) << endl; // return 1, The map is now [[1,1], [2,2]]
	cout << myHashMap.get(3) << endl; // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
	myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
	cout << myHashMap.get(2) << endl; // return 1, The map is now [[1,1], [2,1]]
	myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
	cout << myHashMap.get(2) << endl; // return -1 (i.e., not found), The map is now [[1,1]]
	return 0;
}
