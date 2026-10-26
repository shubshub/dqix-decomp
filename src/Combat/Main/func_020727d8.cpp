#include <globaldefs.h>

struct Struct_020727d8 {
    void* entries;
    short capacity;
    short count;
};

// USA: func_020727d8
extern "C" ARM void func_020727d8(struct Struct_020727d8* list) {
    list->entries = 0;
    list->capacity = 0;
    list->count = 0;
}
