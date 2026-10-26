#include <globaldefs.h>

struct Struct_02070f98 {
    unsigned char data[0x84];
};

struct Struct_02070f98_2 {
    unsigned int count : 12;
    unsigned int pad : 20;
    struct Struct_02070f98* base;
};

// USA: func_02070f98
extern "C" ARM struct Struct_02070f98* func_02070f98(struct Struct_02070f98_2* list, int index) {
    if (index < 0 || index >= (int)list->count || list->base == NULL) {
        return NULL;
    }
    return &list->base[index];
}
