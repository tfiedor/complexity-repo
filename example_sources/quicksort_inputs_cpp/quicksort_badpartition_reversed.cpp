#include "../structures/sorts.h"
#include "../profile_api.h"

const int MAX_SORT_ARR_LEN = 10000;
const int SORT_ARR_LEN_INC = 50;


int main() {

    // Run bad quicksort on different scales with reverse sorted input
    for(int i = SORT_ARR_LEN_INC; i <= MAX_SORT_ARR_LEN; i += SORT_ARR_LEN_INC) {
        int *input = new int[i];
        _profapi_register_size_value(input, false, (size_t)i);

        for(int j = 0; j < i; j++) {

            input[j] = i - j - 1;
        }

        _profapi_using_size_value(input, (size_t)i);
        QuickSortBad(input, i);
        _profapi_unregister_size(input);
        delete[] input;
    }

    return 0;
}