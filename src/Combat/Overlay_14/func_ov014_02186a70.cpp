#include <globaldefs.h>

struct Struct020dfc40;
struct Struct_02081ee4;
struct Struct_02081ee4_2;

extern "C" void func_ov014_021844c4(void* obj);
extern "C" void func_020972b0(int* p);
extern "C" void KeyTable_Reset(Struct020dfc40* p);
extern "C" void SpriteContext_Init(char* p);
extern "C" void func_02081ee4(Struct_02081ee4* obj, Struct_02081ee4_2* sub);
#include "std_library_functions.h"

// USA: func_ov014_02186a70
extern "C" ARM void func_ov014_02186a70(char* obj) {
    func_ov014_021844c4(obj);
    func_020972b0((int*)(obj + 0xa4));
    *(int*)(obj + 0xb4) = 0;
    *(int*)(obj + 0xb8) = 0;
    *(int*)(obj + 0xbc) = 0;
    *(int*)(obj + 0xc0) = 0;
    *(int*)(obj + 0xc4) = 0;
    *(int*)(obj + 0xc8) = 0;
    *(int*)(obj + 0xcc) = 0;
    *(int*)(obj + 0xd0) = 0;
    *(int*)(obj + 0xd4) = 0;
    *(int*)(obj + 0xd8) = 0;
    *(int*)(obj + 0xdc) = 0;
    KeyTable_Reset((Struct020dfc40*)(obj + 0xe0));
    SpriteContext_Init(obj + 0xf8);
    func_02081ee4((Struct_02081ee4*)(obj + 0x14c), (Struct_02081ee4_2*)(obj + 0x158));
    *(int*)(obj + 0x15c) = 0;
    *(int*)(obj + 0x160) = 0;
    *(int*)(obj + 0x164) = 0;
    *(int*)(obj + 0x168) = -1;
    *(short*)(obj + 0x170) = -1;
    *(short*)(obj + 0x172) = -1;
    *(short*)(obj + 0x174) = -1;
    *(short*)(obj + 0x176) = -1;
    *(short*)(obj + 0x178) = -1;
    *(char*)(obj + 0x17a) = 0;
    *(char*)(obj + 0x17b) = 0;
    *(char*)(obj + 0x17c) = 0;
    *(char*)(obj + 0x17d) = -1;
    *(char*)(obj + 0x17e) = 0;
    *(char*)(obj + 0x17f) = 0;
    *(short*)(obj + 0x180) = 0;
    memset(obj + 0x182, 0, 0x10);
}
