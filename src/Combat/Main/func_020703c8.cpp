#if defined(jpn)
enum { Enum_020703c8_17604 = 0x4214 };
#else
enum { Enum_020703c8_17604 = 0x44c4 };
#endif

#include <globaldefs.h>
#include "Resource/GameResources.h"


extern "C" void* Scenario_GetInstance(void);
extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021d0924(int kind, unsigned char index, int flags, unsigned short arg3);

struct Struct_0206dee8;
struct Struct_0206dec8;
extern "C" void func_0206dee8(Struct_0206dee8* base, unsigned char index, unsigned char* outA, unsigned char* outB, unsigned char* arg4);
extern "C" void func_0206dec8(Struct_0206dec8* base, unsigned char index, unsigned char a, unsigned char b, unsigned char c);

extern "C" void func_0206e080(char* base, int index);
extern "C" void func_0206e0d0(char* base, int index);
extern "C" void func_0206ebf4(char* obj);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_0206df14(unsigned char* obj);

// USA: func_020703c8
extern "C" ARM void func_020703c8(int index, int arg1, int arg2, int second) {
    unsigned char var0;
    unsigned char var1;
    unsigned char var2;
    void* entry = Scenario_GetInstance();
    int* state = LinkSession_GetInstance();
    char* owner = *(char**)((char*)GetGameResources() + Enum_020703c8_17604);

    func_0206dee8((Struct_0206dee8*)entry, index, &var0, &var1, &var2);
    if (var2 + (var0 * 10000 + var1 * 100) >= second + (arg1 * 10000 + arg2 * 100)) {
        return;
    }
    if (var0 != arg1) {
        func_0206e080((char*)entry, index);
        func_0206ebf4(owner);
    } else if (var1 != arg2) {
        func_0206e0d0((char*)entry, index);
        func_0206ebf4(owner);
    }
    func_0206dec8((Struct_0206dec8*)entry, index, arg1, arg2, second);
    if (LinkSession_IsActive(state) != 0 && LinkSession_IsHostOrSolo(state) != 0) {
        func_ov017_021d0924(2, index, 0, second | (arg1 << 10 | arg2 << 5));
    }
    func_0206df14((unsigned char*)entry);
}
