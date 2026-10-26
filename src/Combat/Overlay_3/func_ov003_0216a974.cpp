#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { kRegione4 = 0xe0 };
enum { Enum_ov003_0216a974_2400 = 0x800 };
#else
enum { kRegione4 = 0xe4 };
enum { Enum_ov003_0216a974_2400 = 0x960 };
#endif

#include "std_library_functions.h"

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
extern "C" void func_ov003_02169a84(char* base, char* dst, int flag);
extern "C" void func_ov003_02169d10(void* base, void* dst, int flag);

// USA: func_ov003_0216a974
extern "C" ARM void func_ov003_0216a974(unsigned char* obj, int mode, int flag) {
    unsigned char* elem = (unsigned char*)func_0205d81c((struct Struct_0205d81c*)(obj + kRegione4), mode);
    if (elem == 0) return;

    if (flag) elem[0xc5] |= 0x40;
    else elem[0xc5] &= ~0x40;
    flag = 0;

    if (*(unsigned char*)(elem + 0xc5) & 2) flag = 1;
    memset(*(void**)(obj + 0x7c), 0, Enum_ov003_0216a974_2400);

    switch (mode) {
    case 1: func_ov003_02169a84((char*)obj, *(char**)(obj + 0x7c), flag); break;
    case 2: func_ov003_02169d10(obj, *(void**)(obj + 0x7c), flag); break;
    }
#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)(obj + kRegione4), mode, *(int*)(obj + 0x7c), 1);
#else
    Window_SetPaneText((struct StructA0205d5d0*)(obj + kRegione4), mode, *(int*)(obj + 0x7c), 1, 0);
#endif
}
