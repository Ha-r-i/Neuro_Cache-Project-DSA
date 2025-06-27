#include <bits/stdc++.h>
using namespace std;

#include "NeuroCache.h"
// #include "utils.h"
#include <limits>

NeuroCache::NeuroCache(int cap){
    capacity= cap;
    timestamp=0;
}

int NeuroCache::get(int key) {
    timestamp++;
    if (cache.find(key) == cache.end()) {
        return -1; // Key not found
    }
    // Update metadata
    auto temp= cache[key];
    temp.second.lastUsedTime = timestamp;
    temp.second.frequency++;
    temp.second.score = computeScore(temp.second);
    cache[key] = temp;
    return temp.first;
}

void NeuroCache::put(int key,int val){
    timestamp++;
    if(cache.find(key)!=cache.end()){
        auto temp=cache[key];
        temp.first=val;
        temp.second.lastUsedTime = timestamp;
        temp.second.frequency++;
        temp.second.score = computeScore(temp.second);
        cache[key] = temp;
    }
    else {
        if (cache.size() >= capacity) {
            evict();
        }
        Metadata meta = {1, timestamp, 0.0f};
        cache[key] = {val, meta};
    }
}

void NeuroCache::evict() {
    int minScore = INT_MAX; // Initialize to maximum possible integer value
    // Find the key with the minimum score;
    int keyToEvict = -1;

    for (auto it : cache) {
        int score = computeScore(it.second.second);
        if (score < minScore) {
            minScore = score;
            keyToEvict = it.first;
        }
    }

    if (keyToEvict != -1) {
        cache.erase(keyToEvict);
    }
    if(keyToEvict == -1) {
        cout << "No key to evict" << endl;
    }
}

float NeuroCache::computeScore(const Metadata& data) {
    // Example scoring function: frequency * lastUsedTime
    float score = static_cast<float>(data.frequency) / (this->timestamp - data.lastUsedTime + 1);
    return score;
}

void NeuroCache::printCache() {
    for (auto it : cache) {
        cout << "Key: " << it.first << ", Value: " << it.second.first
             << ", Frequency: " << it.second.second.frequency
             << ", Last Used Time: " << it.second.second.lastUsedTime
             << ", Score: " << it.second.second.score << endl;
    }
}

