#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for find()

using namespace std;

class HashTable {
    vector<list<int>> table;  // Hash Table (vector of linked lists)
    int size;  // Number of buckets

public:
    HashTable(int bucketSize) {
        size = bucketSize;
        table.resize(size);
    }

    // Hash function
    int getHashValue(int key) {
        return key % size;
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = getHashValue(key);
        table[index].push_back(key);
    }

    // Search key in the hash table
    bool search(int key) {
        int index = getHashValue(key);
        auto it = find(table[index].begin(), table[index].end(), key);
        return it != table[index].end();
    }

    // Delete key from the hash table
    void remove(int key) {
        int index = getHashValue(key);
        auto it = find(table[index].begin(), table[index].end(), key);

        if (it != table[index].end()) {
            table[index].erase(it);
            cout << key << " is deleted from the hash table." << endl;
        } else {
            cout << key << " is not found in the hash table." << endl;
        }
    }

    // Display Hash Table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            for (int value : table[i]) {
                cout << value << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);  // Creating a hash table with 10 buckets

    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(5);
    hashTable.insert(95);

    cout << "Hash Table before deletion:" << endl;
    hashTable.display();

    // Searching for elements
    int searchKey = 25;
    if (hashTable.search(searchKey)) {
        cout << searchKey << " is present in the hash table." << endl;
    } else {
        cout << searchKey << " is not found." << endl;
    }

    // Deleting an element
    hashTable.remove(25);

    cout << "\nHash Table after deletion:" << endl;
    hashTable.display();

    return 0;
}

