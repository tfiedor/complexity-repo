#include <algorithm>
#include <random>
#include <chrono>
#include <climits>
#include "../structures/sorts.h"
#include "../../profile_api.h"

const int MAX_SORT_ARR_LEN = 10000;
const int SORT_ARR_LEN_INC = 50;

int main() {

    // init the rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_MAX - 1);

    // perform the sort many times on a different scale
    for(int i = SORT_ARR_LEN_INC; i <= MAX_SORT_ARR_LEN; i += SORT_ARR_LEN_INC) {
        int *input = new int[i];
        _profapi_register_size_value(input, false, (size_t)i);

        for(int j = 0; j < i; j++) {
            input[j] = j;
        }

        _profapi_using_size_value(input, (size_t)i);
        InsertSort(input, i);
        _profapi_unregister_size(input);
        delete[] input;
    }
}