#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "SLList.h"
#include "SLListcls.h"
#include "../profile_api.h"

#define R_MIN 1
#define R_MAX 100000
#define R_RANGE(min, max) (rand() % ((R_MAX) - (R_MIN)) + (R_MIN))

int main() {

    srand(time(NULL));

    SLList mylist;
    _profapi_register_size_address(&mylist, false, &mylist.size);
    SLList_init(&mylist);
    for(int i = 0; i < 200; ++i) {
        _profapi_using_size_address(&mylist);
        int inserted_item = i + 1;
        if(rand() % 3 == 0) {
            SLList_insert(&mylist, inserted_item);
            _profapi_using_size_address(&mylist);
        } else {
            SLList_search(&mylist, inserted_item);
            _profapi_using_size_address(&mylist);
        }
    }
    _profapi_using_size_address(&mylist);
    SLList_destroy(&mylist);

//    SLListcls clslist;
//    for(int i = 0; i < 100000; i++) {
//        clslist.Insert(i + 1);
//    }
//    clslist.Search(3);

    return 0;
}
