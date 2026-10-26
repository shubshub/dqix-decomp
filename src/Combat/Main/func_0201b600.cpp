#include <globaldefs.h>
#if defined(jpn)
enum { kNodeOffset = 0x43c };
#else
enum { kNodeOffset = 0x41c };
#endif

struct Struct_0201b600 { unsigned short key; unsigned char pad[0x6e]; };
struct Struct_0201b600_2 {
    int f0;
    unsigned char pad4[0x10];
    int count;
    unsigned char pad18[0x2c];
    struct Struct_0201b600* arr;
    unsigned char unknown_48_[0xc];
    struct Struct_0201b600_2* next;
};
struct Obj0201b600 {
    unsigned char pad0[kNodeOffset];
    struct Struct_0201b600_2* head;
    unsigned char unknown_420_[4];
    int f424;
};

// USA: func_0201b600
extern "C" ARM struct Struct_0201b600* func_0201b600(Obj0201b600* obj, int key1, unsigned short key2) {
    struct Struct_0201b600_2* node;
    int count;
    int i;
    if (obj->f424 != 0) return NULL;
    node = obj->head;
    while (node != NULL) {
        if (node->f0 == key1) break;
        node = node->next;
    }
    if (node != NULL) {
        struct Struct_0201b600* result = NULL;
        count = node->count;
        for (i = 0; i < count; i++) {
            if (key2 == node->arr[i].key) { result = &node->arr[i]; break; }
        }
        return result;
    }
    return NULL;
}
