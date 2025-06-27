# 🧠 NeuroCache – Intelligent Cache System

NeuroCache is a modern, adaptive caching system that uses learning-based logic to optimize data retention and eviction. Unlike traditional caches like **LRU (Least Recently Used)** or **LFU (Least Frequently Used)** that follow static rules, NeuroCache dynamically learns and scores cached items based on their usage frequency and recency.

This intelligent behavior helps improve cache hit rates in scenarios like:
- Web browsers
- CPU/GPU memory caches
- CDN edge caching
- Recommendation systems
- Operating system page replacement

---

## 🚀 Features

✅ Learns from usage patterns  
✅ Eviction based on frequency and last-used time  
✅ Lightweight and modular  
✅ Clear output to visualize evictions and score changes  
✅ Supports customization of scoring logic

---

## 🧠 How NeuroCache Works

NeuroCache assigns a **score** to each cache item:

score = frequency / (currentTime - lastUsedTime + 1)


- 📈 High frequency → more important  
- ⏱️ Recently used → higher priority  
- 🧮 Lower-scoring items get evicted when cache is full

This balances both **recency and frequency**, similar to a hybrid between LRU and LFU, with tunable logic for smarter decisions.

---
### Data Structure Visualization

![Data Structure](Assets/Screenshot%202025-06-27%20153311.png)


## 🧾 Example Usage

```cpp
NeuroCache cache(3);  // Set capacity to 3

cache.put(1, 100);    // Add key 1
cache.put(2, 200);    // Add key 2
cache.put(3, 300);    // Add key 3

cache.get(1);         // Access key 1 (boosts frequency)
cache.put(4, 400);    // Cache full → evict based on lowest score
cache.get(2);         // Key 2 might be evicted, will return -1 if so
```

### Output Example 1  
Initial insertions and access operations:

![Output ](Assets/Screenshot%202025-06-27%20152542.png)
![Output ](Assets/Screenshot%202025-06-27%20152847.png)

| Function            | Time Complexity          | Space Complexity | Description                                            |
| ------------------- | ------------------------ | ---------------- | ------------------------------------------------------ |
| `NeuroCache(int)`   | O(1)                     | O(1)             | Initializes cache capacity and timestamp.              |
| `get(int key)`      | O(1) average             | O(1)             | Retrieves value and updates metadata using a hash map. |
| `put(int key, int)` | O(1) average, O(n) worst | O(1)             | Adds/updates key. Triggers eviction if cache is full.  |
| `evict()`           | O(n)                     | O(1)             | Scans entries to evict one with the lowest score.      |
| `computeScore()`    | O(1)                     | O(1)             | Calculates eviction score from frequency and recency.  |
| `printCache()`      | O(n)                     | O(1)             | Displays all key-value pairs in the cache.             |


## Made by Hari Balan K


