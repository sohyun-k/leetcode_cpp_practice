#pragma once

#include <list>
#include <unordered_map>

class LRUCache {
public:
    int capacity;
    std::list<std::pair<int, int>> used_list;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        else {
            used_list.splice(used_list.begin(), used_list, cache.find(key)->second);
            return cache.find(key)->second->second;
        }
    }

    void put(int key, int value) {
        if (get(key) != -1) { 
            cache.find(key)->second->second = value;
            return;
        }
        if (cache.size() == capacity) {
            int selectedKey = used_list.back().first;
            used_list.pop_back();
            cache.erase(selectedKey);
        }
        used_list.emplace_front(key, value);
        cache[key] = used_list.begin();
    }
};

