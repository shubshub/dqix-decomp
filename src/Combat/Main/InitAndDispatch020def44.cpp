#include <globaldefs.h>

struct Struct020deeb8 {
    unsigned char pad[0xc];
    int field_c;
    int field_10;
};

struct Buf020def44 {
    unsigned char pad[0x14];
};

int InitStruct020deeb8(int a, struct Struct020deeb8* b, int c, int d, int e);
extern "C" int ItemTable_CopyIds(int a, void* b, void* c, short* d, int e);

// USA: func_020def44
ARM int InitAndDispatch020def44(int a0, int a1, int a2, short a3) {
    struct Struct020deeb8 st;
    struct Buf020def44 other;
    InitStruct020deeb8((int)&other, &st, a0, a1, a2);
    return ItemTable_CopyIds(0, &st, &other, &a3, 1);
}
