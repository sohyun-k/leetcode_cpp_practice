#pragma once
#include <map>
#include <vector>
using namespace std;

class LRUCache {
public:
    map<int, int> cache;
    vector<int> keys;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            recentlyUsed(key);
            return cache.find(key)->second;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache.find(key)->second = value;
            recentlyUsed(key);
        }
        else {
            if (cache.size() < capacity) {
                cache.insert(pair<int, int>(key,value));
                keys.push_back(key);
            }
            else {
                int selectedKey = keys.at(0);
                keys.erase(keys.begin());
                cache.erase(selectedKey);
                keys.push_back(key);
                cache.insert(pair<int, int>(key, value));
            }
        }
    }
    void recentlyUsed(int key) {
        keys.erase(remove(keys.begin(), keys.end(), key), keys.end());
        keys.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */