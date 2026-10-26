#include <globaldefs.h>

struct Struct_ov004_021549e4_3 {
    char pad[0x20];
    unsigned short* table;
    unsigned short count;
    unsigned short width;
};

// USA: func_ov023_021f9b6c
extern "C" ARM unsigned int func_ov023_021f9b6c(struct Struct_ov004_021549e4_3* obj, unsigned int a, unsigned int b) {
    if (!obj->table) return 0;
    if (obj->count <= a || obj->width <= b) return 0;
    return obj->table[a * obj->width + b];
}
