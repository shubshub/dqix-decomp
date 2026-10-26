#include <globaldefs.h>

#if defined(jpn)
namespace { enum { Enum_0206b7b0_2324 = 0x7e4, Enum_0206b7b0_324 = 0x104 }; }
// JPN: func_0206cfd4
extern "C" ARM void func_0206cfd4(char* base) {
#else
namespace { enum { Enum_0206b7b0_2324 = 0x914, Enum_0206b7b0_324 = 0x144 }; }
// USA: func_0206b7b0
extern "C" ARM void func_0206b7b0(char* base) {
#endif
    short a = *(short*)(base + Enum_0206b7b0_2324);
    short b = *(short*)(base + Enum_0206b7b0_2324 + 4);
    short c = *(short*)(base + Enum_0206b7b0_324 + 4);
    short d = *(short*)(base + Enum_0206b7b0_324 + 6);
    short e = *(short*)(base + Enum_0206b7b0_2324 + 2);
    short v2 = a + b - c;
    if (v2 < 0) v2 = 0;
    short v1 = e - d;
    if (v1 < 0) v1 = 0;
    *(short*)(base + Enum_0206b7b0_324) = v2;
    *(short*)(base + Enum_0206b7b0_324 + 2) = v1;
}
