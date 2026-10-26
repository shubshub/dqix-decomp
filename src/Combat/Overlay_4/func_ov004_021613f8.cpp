#include <globaldefs.h>
#if defined(jpn)
enum{regionCount=4,Enum_ov004_021613f8_11=8,Enum_ov004_021613f8_7=6,Enum_ov004_021613f8_8=7};
#else
enum{regionCount=6,Enum_ov004_021613f8_11=0xb,Enum_ov004_021613f8_7=7,Enum_ov004_021613f8_8=8};
#endif

extern "C" int func_ov004_0215f74c(int unused, int combatantId);
extern "C" void func_ov004_0215fdfc(void*);
extern "C" int func_ov004_0215e9dc(void*, void*, int, int);
extern "C" void func_ov004_0216033c(void*);
extern "C" void func_ov004_02161514(void*);
extern "C" void func_ov004_02161c18(void*);
extern "C" void func_ov004_02162108(void*);
extern "C" void func_ov004_0215ef9c(int);

struct Struct_ov004_0215fdfc;
extern "C" void func_ov023_021f809c(struct Struct_ov004_0215fdfc*, void*);
extern "C" void* func_ov004_0215e4c0(void* a, int key);

extern unsigned char data_ov004_021707e8;

#define D021707e8 ((char*)&data_ov004_021707e8)

// USA: func_ov004_021613f8
extern "C" ARM int func_ov004_021613f8(void* a) {
    if (*(signed char*)(D021707e8 + regionCount) <= 1) return 0;

    void* combatant = *(void**)(D021707e8 + 0x1c);
    if (!func_ov004_0215f74c((int)a, (int)combatant)) {
        func_ov004_0215fdfc(a);
        return 0;
    }

    *(signed char*)(D021707e8 + Enum_ov004_021613f8_11) = *(signed char*)(D021707e8 + Enum_ov004_021613f8_11) - 1;
    if (*(signed char*)(D021707e8 + Enum_ov004_021613f8_11) < 0) {
        *(signed char*)(D021707e8 + Enum_ov004_021613f8_11) = *(signed char*)(D021707e8 + regionCount) - 1;
    }

    switch (*(unsigned char*)(D021707e8 + Enum_ov004_021613f8_7) - 0x64) {
    case 0:
        *(unsigned char*)(D021707e8 + Enum_ov004_021613f8_8) = (unsigned char)func_ov004_0215e9dc(a, *(void**)(D021707e8 + 0x1c), *(unsigned char*)(D021707e8 + Enum_ov004_021613f8_8), 0);
        func_ov004_0216033c(a);
        break;
    case 1:
        *(unsigned char*)(D021707e8 + Enum_ov004_021613f8_8) = (unsigned char)func_ov004_0215e9dc(a, *(void**)(D021707e8 + 0x1c), *(unsigned char*)(D021707e8 + Enum_ov004_021613f8_8), 0);
        func_ov004_02161514(a);
        break;
    case 2:
        func_ov004_0215ef9c(1);
        func_ov004_02161c18(a);
        break;
    case 3:
        func_ov004_0215ef9c(0);
        func_ov004_02162108(a);
        break;
    }

    func_ov023_021f809c((struct Struct_ov004_0215fdfc*)func_ov004_0215e4c0(a, 3), a);
    return 0;
}
