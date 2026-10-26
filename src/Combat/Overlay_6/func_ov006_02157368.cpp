#include <globaldefs.h>

struct Struct_ov006_02157368_2 {
    short id;
    char pad[0x18 - 2];
};

struct Struct_ov006_02157368 {
    char pad0[8];
    struct Struct_ov006_02157368_2* arr;
    char pad1[0x14 - 0xc];
    unsigned short count;
};

// USA: func_ov006_02157368
extern "C" ARM struct Struct_ov006_02157368_2* func_ov006_02157368(struct Struct_ov006_02157368* list, int id) {
    struct Struct_ov006_02157368_2* arr = list->arr;
    if (arr == 0) {
        return 0;
    }
    unsigned short count = list->count;
    if (count == 0) {
        return 0;
    }
    for (unsigned short i = 0; i < count; i++) {
        struct Struct_ov006_02157368_2* e = &arr[i];
        if (e->id == id) {
            return e;
        }
    }
    return 0;
}
