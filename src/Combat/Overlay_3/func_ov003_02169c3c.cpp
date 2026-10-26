#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02169c3c_2400 = 0x800 };
enum { kRegione4 = 0xe0 };
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
enum { kRegione4 = 0xe4 };
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

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Elem_0205d81c;
struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);

extern "C" void func_ov003_02169d10(void* obj, void* arg1, int flag);
#if !defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov003_02169c3c
extern "C" ARM void func_ov003_02169c3c(char* obj) {
    func_0205de24((struct Struct0205de24*)(obj + kRegione4), 0, 2);

    *(short*)(obj + Enum_ov003_02169c3c_388) = 0xe;
    *(short*)(obj + Enum_ov003_02169c3c_390) = 7;
    *(short*)(obj + Enum_ov003_02169c3c_392) = 0x11;
    *(short*)(obj + Enum_ov003_02169c3c_394) = 7;
    *(short*)(obj + Enum_ov003_02169c3c_396) = 8;
    *(short*)(obj + Enum_ov003_02169c3c_398) = 0x10;
    *(short*)(obj + Enum_ov003_02169c3c_400) = 0xc;
    *(short*)(obj + Enum_ov003_02169c3c_402) = 0xe;

    obj[Enum_ov003_02169c3c_405] = 2;
    obj[Enum_ov003_02169c3c_409] = 1;
    obj[Enum_ov003_02169c3c_1262] = 3;

    memset(*(void**)(obj + 0x7c), 0, Enum_ov003_02169c3c_2400);
    func_ov003_02169d10(obj, *(void**)(obj + 0x7c), 0);
#if defined(jpn)
    Window_OpenPane(obj + kRegione4, *(void**)(obj + 0x7c), 0, 0, 0, 1, 0);
#else
    Window_OpenPane(obj + kRegione4, *(void**)(obj + 0x7c), 0, 0, 0, 0, 0, 1);
#endif

    struct Elem_0205d81c* e = func_0205d81c((struct Struct_0205d81c*)(obj + kRegione4), 2);
    *((unsigned char*)e + 0xc6) = 0;
}
