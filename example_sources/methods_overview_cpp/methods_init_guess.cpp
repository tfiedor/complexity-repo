#include <random>
#include <chrono>
#include <climits>
#include "../profile_api.h"

const int MAX_STACK_SIZE = 1000000;

// the stack search operation
int stack_search(std::vector<int> &mystack, int key) {
    auto stack_size = mystack.size();
    for(int i = 0; i < stack_size; i++) {
        if(mystack[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {

    // init the rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_MAX - 1);

    // init the stack
    std::vector<int> mystack;
    _profapi_register_size_value(&mystack, false, mystack.size());

    // perform the operations
    for(int i = 0; i < MAX_STACK_SIZE; i++) {
        mystack.push_back(dis(gen));

        if(i % 1000 == 0) {
            _profapi_using_size_value(&mystack, mystack.size());
            stack_search(mystack, INT_MAX);
        }
    }
}