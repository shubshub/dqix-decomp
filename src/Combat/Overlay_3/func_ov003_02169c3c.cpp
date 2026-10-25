#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02169c3c_2400 = 0x800 };
enum { Enum_ov003_02169c3c_228 = 0xe0 };
enum { Enum_ov003_02169c3c_388 = 0x180 };
enum { Enum_ov003_02169c3c_390 = 0x182 };
enum { Enum_ov003_02169c3c_392 = 0x184 };
enum { Enum_ov003_02169c3c_394 = 0x186 };
enum { Enum_ov003_02169c3c_396 = 0x188 };
enum { Enum_ov003_02169c3c_398 = 0x18a };
enum { Enum_ov003_02169c3c_400 = 0x18c };
enum { Enum_ov003_02169c3c_402 = 0x18e };
enum { Enum_ov003_02169c3c_405 = 0x191 };
enum { Enum_ov003_02169c3c_409 = 0x195 };
enum { Enum_ov003_02169c3c_1262 = 0x4ea };
#else
enum { Enum_ov003_02169c3c_2400 = 0x960 };
enum { Enum_ov003_02169c3c_228 = 0xe4 };
enum { Enum_ov003_02169c3c_388 = 0x184 };
enum { Enum_ov003_02169c3c_390 = 0x186 };
enum { Enum_ov003_02169c3c_392 = 0x188 };
enum { Enum_ov003_02169c3c_394 = 0x18a };
enum { Enum_ov003_02169c3c_396 = 0x18c };
enum { Enum_ov003_02169c3c_398 = 0x18e };
enum { Enum_ov003_02169c3c_400 = 0x190 };
enum { Enum_ov003_02169c3c_402 = 0x192 };
enum { Enum_ov003_02169c3c_405 = 0x195 };
enum { Enum_ov003_02169c3c_409 = 0x199 };
enum { Enum_ov003_02169c3c_1262 = 0x4ee };
#endif

#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#endif
#include "std_library_functions.h"

struct Struct_0205de24_2;
extern "C" void func_0205de24(struct Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);

struct Struct_0205d0e0;
struct Struct_0205d81c;
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);

extern "C" void func_ov003_02169d10(void* arg0, void* arg1, int arg2);
#if !defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov003_02169c3c
extern "C" ARM void func_ov003_02169c3c(char* arg0) {
    func_0205de24((struct Struct_0205de24_2*)(arg0 + Enum_ov003_02169c3c_228), 0, 2);

    *(short*)(arg0 + Enum_ov003_02169c3c_388) = 0xe;
    *(short*)(arg0 + Enum_ov003_02169c3c_390) = 7;
    *(short*)(arg0 + Enum_ov003_02169c3c_392) = 0x11;
    *(short*)(arg0 + Enum_ov003_02169c3c_394) = 7;
    *(short*)(arg0 + Enum_ov003_02169c3c_396) = 8;
    *(short*)(arg0 + Enum_ov003_02169c3c_398) = 0x10;
    *(short*)(arg0 + Enum_ov003_02169c3c_400) = 0xc;
    *(short*)(arg0 + Enum_ov003_02169c3c_402) = 0xe;

    arg0[Enum_ov003_02169c3c_405] = 2;
    arg0[Enum_ov003_02169c3c_409] = 1;
    arg0[Enum_ov003_02169c3c_1262] = 3;

    memset(*(void**)(arg0 + 0x7c), 0, Enum_ov003_02169c3c_2400);
    func_ov003_02169d10(arg0, *(void**)(arg0 + 0x7c), 0);
#if defined(jpn)
    Window_OpenPane(obj + kRegione4, *(void**)(obj + 0x7c), 0, 0, 0, 1, 0);
#else
    Window_OpenPane(obj + kRegione4, *(void**)(obj + 0x7c), 0, 0, 0, 0, 0, 1);
#endif

    struct Struct_0205d0e0* var0 = func_0205d81c((struct Struct_0205d81c*)(arg0 + Enum_ov003_02169c3c_228), 2);
    *((unsigned char*)var0 + 0xc6) = 0;
}
