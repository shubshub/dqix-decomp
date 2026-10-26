#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov001_0215af34;
extern "C" void func_ov017_021d6148(Struct_ov001_0215af34* o, unsigned int v);
extern "C" void* func_ov017_021bbbe4(void* obj);

struct Struct_ov001_0216089c { int type; int *ptr; };
extern "C" void func_ov017_021d6134(Struct_ov001_0216089c* a, int val);

// USA: func_ov001_0216089c
extern "C" ARM int func_ov001_0216089c(void* self) {
#if defined(jpn)
    enum { Enum_ov001_0216089c_1844 = 0x524 };
#else
    enum { Enum_ov001_0216089c_1844 = 0x734 };
#endif
    char* node = (char*)func_ov017_021bbbe4(*(void**)((char*)GetGameResources() + 0x3000 + Enum_ov001_0216089c_1844));
    if (*(signed char*)node < 0) {
        return 0;
    }
    func_ov017_021d6134((Struct_ov001_0216089c*)self, *(unsigned char*)(node + 0x14));
    func_ov017_021d6148((Struct_ov001_0215af34*)((char*)self + 8), *(unsigned int*)(node + 0x18));
    return 1;
}
