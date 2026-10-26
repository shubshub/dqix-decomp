#include <globaldefs.h>

struct Struct_ov023_021db4e4 {
    char pad8[8];
    char* arr;
    char unknown_c_[0x14 - 0xc];
    unsigned short count;
};

// USA: func_ov023_021db4e4
extern "C" ARM void* func_ov023_021db4e4(struct Struct_ov023_021db4e4* obj, short key) {
    char* arr = obj->arr;
    if (!arr) return 0;
    unsigned short count = obj->count;
    if (count == 0) return 0;
    for (unsigned short i = 0; i < count; i++) {
        char* entry = arr + i * 0x18;
        if (*(short*)entry == key) return entry;
    }
    return 0;
}
