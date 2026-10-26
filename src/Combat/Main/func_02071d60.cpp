#include <globaldefs.h>

struct Struct_02071d60_2 {
    short key;
    char pad[0x1e];
};

struct Struct_02071d60 {
    void* field0;
    struct Struct_02071d60_2* data;
    unsigned short field8;
    unsigned short count;
};

// USA: func_02071d60
extern "C" ARM struct Struct_02071d60_2* func_02071d60(struct Struct_02071d60* list, int key) {
    unsigned short i;
    for (i = 0; i < list->count; i++) {
        if (key == list->data[i].key) {
            return &list->data[i];
        }
    }
    return NULL;
}
