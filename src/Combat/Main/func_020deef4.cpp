#include <globaldefs.h>

struct Struct_020deeb8 {
    unsigned char pad[0xc];
    int unknown_c_;
    int unknown_10_;
};

struct Struct_020deef4 {
    unsigned char pad[0x14];
};

extern "C" int func_020deeb8(int a, struct Struct_020deeb8* b, int c, int d, int e);
extern "C" int ItemTable_CopyIds(int a, void* b, void* c, short* d, int e);

// USA: func_020deef4
extern "C" ARM int func_020deef4(int a0, int a1, int a2, short* a3, short a4) {
    struct Struct_020deef4 other;
    struct Struct_020deeb8 st;
    func_020deeb8((int)&other, &st, a0, a1, a2);
    return ItemTable_CopyIds(0, &st, &other, a3, a4);
}
