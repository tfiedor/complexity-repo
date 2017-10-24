#include <algorithm>
#include <random>
#include <chrono>
#include <climits>
#include <iostream>
#include "../structures/skiplist.h"
#include "../profile_api.h"

const int skiplist_max_size = 300000;

int MAX_HEIGHT = 3;
int LEVEL_PROBABILITY = 2;

int main() {

    // init the rng
    srand(time(NULL));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_MAX - 1);

    // init the skip list
    Skiplist mylist = skiplistCreate();
    size_t skiplist_size = 0;
    _profapi_register_size_address(&mylist, false, &skiplist_size);

    // run the skip list operations
    for(int i = 0; i < skiplist_max_size; i++) {
        skiplistInsert(mylist, dis(gen));
        skiplist_size++;

        if(i % 1000 == 0) {
            _profapi_using_size_address(&mylist);
            skiplistSearch(mylist, INT_MAX);
        }
    }
    _profapi_unregister_size(&mylist);
    skiplistDestroy(mylist);
}
