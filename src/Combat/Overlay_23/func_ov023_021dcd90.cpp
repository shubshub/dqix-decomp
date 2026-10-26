#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021dcd90_1947 = 0x717 };
#else
enum { Enum_ov023_021dcd90_1947 = 0x79b };
#endif

#include "std_library_functions.h"

extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);
extern "C" void func_ov023_021dcdf4(void* obj);

struct Struct_ov023_021dcd90 {
    char pad[Enum_ov023_021dcd90_1947];
    unsigned char bit0 : 1;
    unsigned char unknown_79b_1_ : 1;
    unsigned char rest : 6;
};

// USA: func_ov023_021dcd90
extern "C" ARM void func_ov023_021dcd90(Struct_ov023_021dcd90* obj, unsigned char enable) {
    if (obj->unknown_79b_1_ && !enable) {
        memset((void*)GetMainBG1ScreenBase(), 0, 0x800);
        memset((void*)GetMainBG2ScreenBase(), 0, 0x800);
        func_ov023_021dcdf4(obj);
    }
    obj->unknown_79b_1_ = enable;
}
