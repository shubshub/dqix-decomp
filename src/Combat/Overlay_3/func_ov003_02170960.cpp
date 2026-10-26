#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void func_02046380(void);
extern "C" void* __clear(void* dst, int count);
extern "C" void Font_DecodeText(unsigned char* src, char* dst, int n);

struct Struct_020e4b34 { int f0; int f4; unsigned int f8; };
extern "C" void func_020e4b34(Struct_020e4b34* dst, void* a1, int a2, unsigned int a3,
    unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3,
    unsigned char arg8, unsigned char arg9, unsigned char arg10, unsigned char arg11);

extern "C" int StandardStrings_Get(int value);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

extern "C" void func_0204500c(void*, int, int, int);

struct Struct_ov003_02170960 {
    char pad0[0xc];
    unsigned int nibble : 4;
    unsigned int rest : 28;
    char pad1[0x1e];
    unsigned char bit0 : 1;
};

struct Struct_ov003_02170960_2 { char pad[0xd8]; struct Container020e0310* c; };

// USA: func_ov003_02170960
extern "C" ARM void func_ov003_02170960(struct Struct_ov003_02170960_2* obj, int key, struct Struct_ov003_02170960* p3) {
    int g = MessageSystem_GetInstance();
    func_02046380();

    Struct_020e4b34 var1;
    Struct_020e4b34 var2;
    char buf[0x30];
    __clear(buf, 0x30);

    if (p3 != 0) {
        Font_DecodeText((unsigned char*)p3, buf, 1);

        func_020e4b34(&var1, buf, 0, 0, 0, 0, 0, p3->bit0, 0, 1, 0, 1);
        *(void**)(g + 0x10) = &var1;

        int fmt = StandardStrings_Get(p3->nibble);

        func_020e4b34(&var2, (void*)fmt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(void**)(g + 0x28) = &var2;
    }

    int fieldVal = KeyTable_Get(obj->c, (short)key);
    func_0204500c((void*)g, fieldVal, 0, 0xe3);

    *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
    *(int*)(g + 0x99c) = 2;
}
