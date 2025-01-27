//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // Doubly-linked list to store key-value pairs in LRU order.
    unordered_map<int, list<pair<int, int>>::iterator> hashMap; // Maps keys to iterators of the list.

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // If key is not found, return -1.
        if (hashMap.find(key) == hashMap.end()) {
            return -1;
        }

        // Key is found. Move the key-value pair to the front of the list (most recently used).
        auto it = hashMap[key];
        cache.splice(cache.begin(), cache, it);
        return it->second; // Return the value.
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // If the key already exists, update the value and move it to the front.
        if (hashMap.find(key) != hashMap.end()) {
            auto it = hashMap[key];
            it->second = value; // Update value.
            cache.splice(cache.begin(), cache, it);
            return;
        }

        // If the cache is at capacity, remove the least recently used element (back of the list).
        if (cache.size() == capacity) {
            auto lru = cache.back();
            hashMap.erase(lru.first); // Remove from hash map.
            cache.pop_back(); // Remove from list.
        }

        // Insert the new key-value pair at the front of the list.
        cache.emplace_front(key, value);
        hashMap[key] = cache.begin(); // Update hash map with iterator to the new element.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends