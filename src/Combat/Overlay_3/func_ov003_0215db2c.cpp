#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215db2c_2400 = 0x800 };
enum { Enum_ov003_0215db2c_954 = 0x3d2 };
enum { Enum_ov003_0215db2c_955 = 0x3d3 };
enum { Enum_ov003_0215db2c_124 = 0x94 };
enum { Enum_ov003_0215db2c_328 = 0x160 };
enum { Enum_ov003_0215db2c_152 = 0xb0 };
#else
enum { Enum_ov003_0215db2c_2400 = 0x960 };
enum { Enum_ov003_0215db2c_954 = 0x3ba };
enum { Enum_ov003_0215db2c_955 = 0x3bb };
enum { Enum_ov003_0215db2c_124 = 0x7c };
enum { Enum_ov003_0215db2c_328 = 0x148 };
enum { Enum_ov003_0215db2c_152 = 0x98 };
#endif

#include "std_library_functions.h"
#include "Input/Input.h"

struct StructA0205d5d0;
#if !defined(jpn)
#endif
extern "C" void func_ov003_0215e13c(char* arg0, char* arg1, int arg2);
extern "C" void func_ov003_0215de6c(char* arg0, void* arg1);

struct Struct_ov003_0215db2c {
    char unknown_0_[0x30];
    int unknown_30_;
};

struct Struct_ov003_0215db2c_2 {
    int unknown_0_;
    struct Struct_ov003_0215db2c unknown_4_[1];
};

static inline struct Struct_ov003_0215db2c* inline_ov003_0215db2c(struct Struct_ov003_0215db2c_2* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_4_; }

// USA: func_ov003_0215db2c
extern "C" ARM void func_ov003_0215db2c(char* arg0) {
    unsigned char var0 = *(unsigned char*)(arg0 + Enum_ov003_0215db2c_954);
    if (var0 != 0) {
        int var1 = 0;
        if (var0 == 2 && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
            if (inline_ov003_0215db2c((struct Struct_ov003_0215db2c_2*)(arg0 + Enum_ov003_0215db2c_152))->unknown_30_ < 0) {
                return;
            }
            var1 = 1;
        }
        memset(*(void**)(arg0 + Enum_ov003_0215db2c_124), 0, Enum_ov003_0215db2c_2400);
        unsigned char var2 = *(unsigned char*)(arg0 + Enum_ov003_0215db2c_328);
        if (var2 == 1) {
            func_ov003_0215e13c(arg0, *(char**)(arg0 + Enum_ov003_0215db2c_124), var1);
        }
        if (var2 != 0) {
#if defined(jpn)
            Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), page, *(int*)(self + kRegion7c), 1);
#else
            Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), page, *(int*)(self + kRegion7c), 1, 0);
#endif
        }
    }
    if (*(unsigned char*)(arg0 + Enum_ov003_0215db2c_955) != 0) {
        memset(*(void**)(arg0 + Enum_ov003_0215db2c_124), 0, Enum_ov003_0215db2c_2400);
        func_ov003_0215de6c(arg0, *(void**)(arg0 + Enum_ov003_0215db2c_124));
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), 0, *(int*)(self + kRegion7c), 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), 0, *(int*)(self + kRegion7c), 1, 0);
#endif
        *(unsigned char*)(arg0 + Enum_ov003_0215db2c_955) = 0;
    }
}
