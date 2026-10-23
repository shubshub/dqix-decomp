#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215c01c_2400 = 0x800 };
#else
enum { Enum_ov003_0215c01c_2400 = 0x960 };
#endif

#include "std_library_functions.h"

struct Struct_0205d81c;
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);

struct StructA0205d5d0;
extern "C" void func_ov003_0215b6f0(char* base, char* dst, int flag);
extern "C" void func_ov003_0215b964(void* self, void* p, int flag);
extern "C" void func_ov003_0215be70(char* base, char* dst, int flag);

// USA: func_ov003_0215c01c
extern "C" ARM void func_ov003_0215c01c(unsigned char* arg0, int arg1, int arg2) {
    unsigned char* var0 = (unsigned char*)func_0205d81c((struct Struct_0205d81c*)(arg0 + 0xf4), arg1);
    if (var0 == 0) return;

    if (arg2) var0[0xc5] |= 0x40;
    else var0[0xc5] &= ~0x40;
    arg2 = 0;

    if (*(unsigned char*)(var0 + 0xc5) & 2) arg2 = 1;
    memset(*(void**)(arg0 + 0x7c), 0, Enum_ov003_0215c01c_2400);

    switch (arg1) {
    case 1: func_ov003_0215b6f0((char*)arg0, *(char**)(arg0 + 0x7c), arg2); break;
    case 2: func_ov003_0215b964(arg0, *(void**)(arg0 + 0x7c), arg2); break;
    case 3: func_ov003_0215be70((char*)arg0, *(char**)(arg0 + 0x7c), arg2); break;
    }
#if defined(jpn)
    func_0205d5d0((struct Struct_0205d5d0*)(arg0 + 0xf4), arg1, *(int*)(arg0 + 0x7c), 1);
#else
    func_0205d5d0((struct Struct_0205d5d0*)(arg0 + 0xf4), arg1, *(int*)(arg0 + 0x7c), 1, 0);
#endif
}
