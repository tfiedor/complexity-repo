#include <algorithm>
#include <random>
#include <chrono>
#include <climits>
#include "../structures/rbtree.h"
#include "../profile_api.h"

const int rbtree_max_size = 1000000;

int main() {
    // create and init the red black tree
    RedBlackTree<int, int> rbt;
    size_t rbt_size = 0;
    _profapi_register_size_address(&rbt, false, &rbt_size);

    // init the rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_MAX - 1);

    // do the insertion and search
    for(int i = 0; i < rbtree_max_size; i++) {
        _profapi_using_size_address(&rbt);
        rbt.insert(dis(gen), i);
        rbt_size++;

        if(i % 1000 == 0) {
            _profapi_using_size_address(&rbt);
            rbt.search(INT_MAX);
        }
    }
}