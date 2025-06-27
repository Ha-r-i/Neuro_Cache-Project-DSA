#include <iostream>
#include "NeuroCache.h"

using namespace std;

int main() {
    cout << " Creating NeuroCache with capacity = 3\n" << endl;
    NeuroCache cache(3);

    cout << " Inserting (1, 100)\n";
    cache.put(1, 100);
    cache.printCache(); cout << endl;

    cout << " Inserting (2, 200)\n";
    cache.put(2, 200);
    cache.printCache(); cout << endl;

    cout << " Inserting (3, 300)\n";
    cache.put(3, 300);
    cache.printCache(); cout << endl;

    cout << " Accessing key 1 (expect 100): ";
    cout << cache.get(1) << endl;
    cache.printCache(); cout << endl;

    cout << " Inserting (4, 400) -> should trigger eviction\n";
    cache.put(4, 400);
    cache.printCache(); cout << endl;

    cout << " Getting evicted key 2 (expect -1): ";
    cout << cache.get(2) << endl;
    cache.printCache(); cout << endl;

    cout << " Accessing key 3 (expect 300): ";
    cout << cache.get(3) << endl;

    cout << " Updating key 3 to value 333\n";
    cache.put(3, 333);
    cache.printCache(); cout << endl;

    cout << " Inserting (5, 500) -> should trigger eviction\n";
    cache.put(5, 500);
    cache.printCache(); cout << endl;

    cout << " Getting evicted key? Let's check key 4 (could be evicted depending on score): ";
    cout << cache.get(4) << endl;
    cache.printCache(); cout << endl;

    return 0;
}
