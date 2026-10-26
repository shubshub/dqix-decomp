#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0208660c_2;
extern "C" void func_020a0948(struct Struct_0208660c_2* p);

struct Struct_0208660c;
extern "C" void func_020a093c(struct Struct_0208660c* obj, int a, int b, short c);

extern "C" void func_0207c258(void* p);
extern "C" void PartyMemberRecord_Init(void* p);

// Main, originally InitBigManagerStruct0208660c (USA 0x0208660c, EUR 0x0208661c, JPN 0x02086f2c)
extern "C" ARM void Party_Init(char* base) {
    memset(base + 0xc, -1, 0x130);
    memset(base + 0x13c, 0, 0x98);
    func_020a0948((struct Struct_0208660c_2*)(base + 0));
    func_020a093c((struct Struct_0208660c*)(base + 0), (int)(base + 0xc), (int)(base + 0x13c), 0x98);

    func_0207c258(base + 0x1d4);

    memset(base + 0xe10, -1, 0xbc);
    memset(base + 0x2cc + 0xc00, 0, 0x5e);
    func_020a0948((struct Struct_0208660c_2*)(base + 0x204 + 0xc00));
    func_020a093c((struct Struct_0208660c*)(base + 0x204 + 0xc00), (int)(base + 0xe10), (int)(base + 0x2cc + 0xc00), 0x5e);

    *(int*)(base + 0xf68) = 0;
    *(int*)(base + 0xf6c) = 0;
    *(int*)(base + 0xf70) = 0;
    *(int*)(base + 0xf74) = 0;
    *(unsigned char*)(base + 0xf7c) = 0;

    for (int i = 0; i < 0xd; i++) {
        PartyMemberRecord_Init(base + 0xf80 + i * 0x23c);
    }

    *(unsigned char*)(base + 0x2000 + 0xc8c) = 0;

    for (int i = 0; i < 3; i++) {
        memset(base + 0xf2c + i * 0x14, 0, 0x14);
        *(signed char*)(base + 0xf3c + i * 0x14) = -1;
    }

    for (unsigned char j = 0; j < 7; j++) {
        *(signed char*)(base + 0x2000 + 0xc8d + j) = -1;
    }

    *(unsigned char*)(base + 0x2000 + 0xc8d) = 3;
    *(int*)(base + 0x2000 + 0xc94) = 0x452;
    *(unsigned char*)(base + 0xf7d) = 0;
}
