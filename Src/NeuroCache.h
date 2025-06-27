#ifndef NEURO_CACHE_H
#define NEURO_CACHE_H

#include <unordered_map>
#include <utility>
#include <bits/stdc++.h>
using namespace std;



struct Metadata {
    int frequency;
    int lastUsedTime;
    float score;
    Metadata() : frequency(0), lastUsedTime(0), score(0.0f) {}
    Metadata(int freq, int lastUsed, float scr) : frequency(freq), lastUsedTime(lastUsed), score(scr) {}
     
};

class NeuroCache {
private:
    int capacity;
    int timestamp;
    unordered_map<int, pair<int, Metadata>> cache;

    void evict();
    float computeScore(const Metadata& data);

public:
    NeuroCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void printCache(); // Optional
    void clearCache() { cache.clear(); } // Optional

};

#endif
