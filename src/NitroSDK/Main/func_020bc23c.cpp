#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_0210f3e4_2 {
    char pad1[0x2c];
    unsigned char field2c;
    char pad2[0xf];
    unsigned char field3c;
    char pad3[7];
};

struct Struct_0210f824_2 {
    SignedAllocatorList listA;
    SignedAllocatorList listB;
    int field18;
    int field1c;
    unsigned char field20;
};

extern SignedAllocatorList data_0210f3d8;
extern SignedAllocatorList data_0210f3cc;
extern Struct_0210f3e4_2 data_0210f3e4[16];
extern Struct_0210f824_2 data_0210f824[32];

// USA: func_020bc23c
extern "C" ARM void func_020bc23c(void) {
    data_0210f3d8.Initialize(0x14);
    data_0210f3cc.Initialize(0x14);

    {
        int i = 0;
        Struct_0210f3e4_2 *entry = data_0210f3e4;
        do {
            entry->field2c = 0;
            entry->field3c = i;
            data_0210f3cc.InsertAtEnd((SignedAllocatorHeader*)entry);
            entry++;
            i++;
        } while (i < 0x10);
    }

    {
        Struct_0210f824_2 *pool = data_0210f824;
        int i = 0;
        do {
            pool->listA.Initialize(0xc);
            pool->listB.Initialize(0);
            pool->field20 = 0x7f;
            pool->field18 = 1;
            pool->field1c = 0;
            pool++;
            i++;
        } while (i < 0x20);
    }
}
